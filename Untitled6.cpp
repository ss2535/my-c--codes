#include <iostream>
#include <thread>
#include <mutex>  
using namespace std;

mutex mtx; 

void threadFunction() {
    mtx.lock();  
    cout << "Thread is running!" << endl;
    cout << endl << "print shape:" << endl;
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl << endl;
    mtx.unlock(); 
}

void mainThreadFunction() {
    mtx.lock();  
    cout << "Main thread is starting!" << endl;
    mtx.unlock(); 
}

int main() {
    thread myThread(threadFunction); 
    thread mainThread(mainThreadFunction);  

    myThread.join();
    mainThread.join();

    cout << "Main thread is done!" << endl;

    return 0;
}
