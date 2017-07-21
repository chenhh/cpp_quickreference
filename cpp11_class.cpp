#include <iostream>
#include <cstdlib>

using namespace std;

class Parent {
public:
    void func1() {
        cout << "func1 parent" << endl;
    }

    virtual void func2() {
        cout << "func2 in parent" << endl;
    }

    virtual void func3() final{
        cout<<"func3 in parent"<<endl;
    }
};

class Child1 : public Parent {
public:
    void func1() {
        cout << "func1 child1" << endl;
    }

    void func2() override{
        cout << "func2 in child1" << endl;
    }
    
    void func3() const{
        // the function does not override parent function
        cout<<"const func3 in child1"<<endl;
    }
};

int main() {
    Parent* obj1 = new Parent();
    Parent* obj2 = new Child1();
    Child1* obj3 = new Child1();

    obj1->func1();  // func1 parent
    obj2->func1();  // func1 parent

    obj1->func2();  // func2 in parent
    obj2->func2();  // func2 in child1

    obj1->func3();  // func in parent
    obj2->func3();  // func in parent
    obj3->func3();  // const func3 in child1

    return EXIT_SUCCESS;
}