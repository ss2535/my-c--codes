//1- thread
#include <iostream>
#include <thread> 
using namespace std;

void threadFunction() {
    cout << "Thread is running!" << endl;
    cout<<endl<<"print shape:"<<endl;
    for(int i=1;i<=10;i++){
    	for(int j=1;j<=i;j++)
	    cout<<"*";
    	cout<<endl;
    }
    cout<<endl<<endl;
}

int main() {
   
    thread myThread(threadFunction);

    myThread.join();

    cout << "Main thread is done!" << endl;

    return 0;
}
