//3
#include <windows.h>
#include <iostream>
using namespace std;

int main() {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);

    ZeroMemory(&pi, sizeof(pi));

    if(!CreateProcess(
        NULL, 
        "notepad.exe",
        NULL, 
        NULL,
        FALSE, 
        0, 
        NULL,
        NULL,
        &si, 
        &pi 
    )) {
        cout << "CreateProcess failed (" << GetLastError() << ")." << endl;
        return -1;
    }

    // (PCB)- process information
    cout << "Process ID: " << pi.dwProcessId << endl;
    cout << "Thread ID: " << pi.dwThreadId <<endl;
    //
   cout << "Access to the process: " << pi.hProcess <<endl;
    cout << "Access to the thread: " << pi.hThread <<endl;	


    WaitForSingleObject(pi.hProcess, INFINITE);

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}

