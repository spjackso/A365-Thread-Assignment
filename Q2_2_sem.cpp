#include <iostream>
#include <thread>
#include <semaphore.h>
using namespace std;
sem_t sem;

void runMeFirst() {
    cout << "Receiving first thread..." << endl;
    sem_wait(&sem);
    cout << "Got it!" << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Run me first" << endl;
    sem_post(&sem);
}

void runMeSecond() {
    cout << "Receiving second thread..." << endl;
    sem_wait(&sem);
    cout << "Got it!" << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << "I am second" << endl;
    sem_post(&sem);
}

void runMeThird() {
    cout << "Receiving third thread..." << endl;
    sem_wait(&sem);
    cout << "Got it!" << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << "I am third" << endl;
    sem_post(&sem);
}

int main() {
   const int num_threads = 3;
   sem_init(&sem, 0, num_threads);
   thread threads[num_threads];
   
   for (int i = 0; i < num_threads; ++i) {
       threads[i] = thread(runMeFirst, i);
       threads[i] = thread(runMeSecond, i);
       threads[i] = thread(runMeThird, i);
}
    
    for (int i = 0; i < num_threads; ++i) {
    threads[i].join();
    }
    
    sem_destroy(&sem); // destroy the semaphore
    return 0;
}