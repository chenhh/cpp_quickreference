#include <iostream>
#include <cstdlib>
#include <exception>
#include <stdexcept>

using namespace std;

class Parent {
public:

    Parent() {}

    void func1() {
        cout << "func1 parent" << endl;
    }

    virtual void func2() {
        cout << "func2 in parent" << endl;
    }

    virtual void func3() final {
        cout << "func3 in parent" << endl;
    }

    Parent(const Parent &) = delete; //delete copy constructor
    Parent &operator=(const Parent &) = delete; //delete assigment operator
};

class Child1 : public Parent {
public:
    void func1() {
        cout << "func1 child1" << endl;
    }

    void func2() override {
        cout << "func2 in child1" << endl;
    }

    void func3() const {
        // the function does not override parent function
        cout << "const func3 in child1" << endl;
    }
};

class DynamicArr {
public:
    DynamicArr(const int len)
    try : _len(len) {
        parr = new int(len);
    } catch (runtime_error &e) {
        cerr << e.what() << endl;
        exit(-1);
    }

    void show(){
        for (int idx = 0; idx < _len; ++idx) {
            cout<<*(parr+idx)<<endl;
        }
    }

    ~DynamicArr() {
        /*
         * https://wizardforcel.gitbooks.io/effective-cpp/content/10.html
         */
        try {
            delete parr;
            parr = nullptr;
        } catch (exception &e) {
            exit(-1);
        }
    }

private:
    int *parr = nullptr;
    int _len = 0;
};

int main() {
    Parent *obj1 = new Parent();
    Parent *obj2 = new Child1();
    Child1 *obj3 = new Child1();

    obj1->func1();  // func1 parent
    obj2->func1();  // func1 parent

    obj1->func2();  // func2 in parent
    obj2->func2();  // func2 in child1

    obj1->func3();  // func in parent
    obj2->func3();  // func in parent
    obj3->func3();  // const func3 in child1


    DynamicArr myarr(10);
    myarr.show();
    return EXIT_SUCCESS;
}