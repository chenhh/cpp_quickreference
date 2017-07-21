/*
 * http://en.cppreference.com/w/cpp/thread/thread
 */
#include <iostream>
#include <cstdlib>
#include <thread>
#include <mutex>

using namespace std;

static const int num_threads = 10;
mutex gMutex;


void thread_func(int tid) {
    /* when the mLock object is constructed, the gMutex is locked
     * and when the mLock is destroyed, the gMutex will be automatically
     * unlocked.
     * this method is more secure than simple gMutex.lock(), gMutex.unlock()
     * when the thread function is terminated abnormally.
    */
    lock_guard<mutex> mLock(gMutex);
    cout << "tid:" << tid << ", hello world" << endl;

    // gMutex is automatically released when mlock
    // goes out of scope
}


int main() {
    thread pools[num_threads];

    for (int idx = 0; idx < num_threads; ++idx) {
        pools[idx] = thread(thread_func, idx);
    }

    cout<<"thread start:"<<endl;

    for (int idx = 0; idx < num_threads; ++idx) {
        pools[idx].join();
    }
    cout<<"thread finished"<<endl;

    return EXIT_SUCCESS;
}