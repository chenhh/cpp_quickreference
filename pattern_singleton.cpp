#include <iostream>
#include <cstdlib>
using namespace std;

/*
 * basic singleton pattern, lazy initialization
 * but it does not thread safe.
 * thread safe requires lock while creating object.
 */
class Singleton {

public:
    static Singleton* getInstance() {
        if (nullptr == m_instance) {
            m_instance = new Singleton();
        }
        return m_instance;
    }

private:
    // an object that has static storage duration is not initialized explicitly
    static Singleton* m_instance;

    // disallow public constructor
    Singleton(){};
    Singleton(const Singleton& rhs) = delete;
    const Singleton& operator=(const Singleton& rhs) = delete;

};
Singleton* Singleton::m_instance = nullptr;


int main() {
    /*
     * error, the class cannot be constructed by constructor
     * StringSingleton* obj1 = new StringSingleton("hello world");
     * delete obj1;
    */

    Singleton* instance1 = Singleton::getInstance();
    Singleton* instance2 = Singleton::getInstance();
    cout<<"instance1 addr:"<<&(*instance1)<<endl;
    cout<<"instance2 addr:"<<&(*instance2)<<endl;
    delete instance1;
    return EXIT_SUCCESS;
}