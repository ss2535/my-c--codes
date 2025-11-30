#include <iostream>
#include <thread>
#include <semaphore.h>

std::counting_semaphore<1> sem(1);

void critical_section(int id) {
    sem.acquire();
    // ??? ??????
    std::cout << "Thread " << id << " is in the critical section.\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Thread " << id << " is leaving the critical section.\n";
    sem.release();
}

int main() {
    std::thread t1(critical_section, 1);
    std::thread t2(critical_section, 2);
    
    t1.join();
    t2.join();
    return 0;
}
