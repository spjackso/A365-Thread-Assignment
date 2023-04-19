#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
using namespace std;
mutex mtx;
condition_variable cv;
struct requestStructure {
    int request_id; 
    string ip_address;
    string page_requested;

};

queue<requestStructure> msg_queue;
string webPages[10] = {"google.com", "yahoo.com","msg.com","youtube.com",
                       "gmail.com", "facebook.com","twitter.com","reddit.com",
                       "instagram.com","amazon.com"};

void listen() {
    page_requested = webPages;
    
    for (int i = 1; i <= 3; ++i) {
        this_thread::sleep_for( chrono::seconds(1));
    {
        lock_guard< mutex> lock(mtx);
        request_id++;
        cout << ip_address << page_requested << endl; 
        msg_queue.push(i); 
    }
    
    cv.notify_one();
}
}
void do_request() {
    while (true) {
        unique_lock< mutex> lock(mtx);
        cv.wait(lock, []{return !msg_queue.empty();});
        int thread_id = msg_queue.front();
        msg_queue.pop();
        cout << "thread " << thread_id << " completed, request " << request_id << "requesting webpage " << page_requested << endl;
        lock.unlock();
    
    if (message == 5) {
        break;
}
}
}

int main() {
    thread t1(listen);
    thread t2(do_request);
    t1.join();
    t2.join();
    cout << "Main thread finished" << endl;
    return 0;
}
