//4
#include <windows.h>
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);

    ZeroMemory(&pi, sizeof(pi));

    const char* filename = "sharedfile.txt";

    ofstream outfile(filename);
    if (!outfile) {
        cout << "Failed to create file." << endl;
        return -1;
    }
    outfile << "Hello from the parent process...";
    outfile.close();

    string command = "notepad.exe " + string(filename);
    if (!CreateProcess(
        NULL, 
        &command[0],
        NULL, 
        NULL,
        FALSE,
        0,
        NULL,
        NULL,
        &si,
        &pi
    )) {
        cout << "CreateProcess failed (" << GetLastError() << ")." <<endl;
        return -1;
    }

    WaitForSingleObject(pi.hProcess, INFINITE);

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}
