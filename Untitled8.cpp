#include <iostream>
#include <thread>
#include <semaphore.h>
using namespace std;

sem_t semaphore;

void accessResource(int threadId) {
    sem_wait(&semaphore); 
    cout << "Thread " << threadId << " is accessing the resource." << endl;
    this_thread::sleep_for(chrono::seconds(1)); 
    cout << "Thread " << threadId << " is leaving the resource." << endl;
    sem_post(&semaphore); 
}

int main() {
    sem_init(&semaphore, 0, 1);

    thread threads[5];
    for (int i = 0; i < 5; i++) {
        threads[i] = thread(accessResource, i);
    }

    for (int i = 0; i < 5; i++) {
        threads[i].join();
    }

    sem_destroy(&semaphore); 
    return 0;
}