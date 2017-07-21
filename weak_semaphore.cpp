/*
 * https://blog.poxiao.me/p/multi-threading-in-cpp11-part-3-condition-variable/
 */
#include <iostream>
#include <cstdlib>
#include <mutex>
#include <thread>
#include <condition_variable>
using namespace std;

static const int num_threads = 10;



class WeakSemaphore {
public:

    WeakSemaphore(int count_ = 0) : count{count_} {}

    void signal() {
        unique_lock<mutex> lck(mtx);
        ++count;
        cv.notify_one();
    }

    void wait() {
        unique_lock<mutex> lck(mtx);
        while (count == 0) {
            cv.wait(lck);
        }

        --count;
    }

private:

    mutex mtx;
    condition_variable cv;
    int count;
};

WeakSemaphore g_semaphore(3);

void worker() {
    g_semaphore.wait();
    auto thread_id = this_thread::get_id();
    cout<<"this id:"<<thread_id<<endl;
    g_semaphore.signal();
}


int main() {
    thread pools[num_threads];
    for (int idx = 0; idx < num_threads; ++idx) {
        pools[idx]= thread(worker);
    }
    for (int idx = 0; idx < num_threads; ++idx) {
        pools[idx].join();
    }

    return EXIT_SUCCESS;
}
