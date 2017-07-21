#include <iostream>
#include <cstdlib>

using namespace std;

class Point {
    // constructor
    Point() : x(0), y(0) {}

    Point(int lx, int ly) : x(lx), y(ly) {}

    Point(const Point &rpoint) {
        this->x = rpoint.x;
        this->y = rpoint.y;
    }

    //assignment
    Point operator=(const Point &rpoint) {
        this->x = rpoint.x;
        this->y = rpoint.y;
    }

    // const membership function
    int getX() const {
        return this->x;
    }

    double square_sum() const {
        return x * x + y * y;
    }

    // non-const membership function
    int setX(int newX) {
        this->x = newX;
    }

private:
    int x = 0;
    int y = 0;
};


int main() {
    /*
     * const variable, it cannot be changed.
     */
    const int v1 = 10;
    // v1 = 20; error
    cout << "const variable v1=" << v1 << endl;

    /*
     * reference to const variable
     */
    // int &v2 = v1; error
    const int &v2 = v1;
    // v2 = 20; error
    cout << "const reference to v1, v2=" << v2 << endl;

    /*
     * rvalue reference
     */
    int variable = 20;
    const int&& rref = variable + 10;
    // rref += 10; error
    cout<<"rref: "<<rref<<endl;

    /*
     * const pointer to a value
     * the value can be changed by the pointer,
     * but the pointer cannot point another variable
     */
    int v3 = 30;
    int *const pv3 = &v3;

    // the value can be changed by itself
    v3 = 33;
    // v3=33, pv3=33
    cout << "v3=" << v3 << ", pv3=" << *pv3 << endl;

    // the value can be changed from the pointer
    *pv3 = 36;
    // v3=36, pv3=36
    cout << "v3=" << v3 << ", pv3=" << *pv3 << endl;

    // the pointer cannot point a new value
    int v33 = 39;
    // pv3 = &v33; error


    /*
     * pointer to a const value
     * the value cannot be changed from the pointer
     * but the pointer can point to another variable
     */
    int v4 = 40;
    const int *pv4 = &v4;
    v4 = 44;
    // the value can be changed by itself
    cout << "v4=" << v4 << ", pv4=" << *pv4 << endl;

    // the value cannot be changed by the pointer
    //*pv4 = 46;  //error

    // the pointer can point to another value
    int v44 = 444;
    // v4=44, pv4=444
    pv4 = &v44;
    cout << "v4=" << v4 << ", pv4=" << *pv4 << endl;

    /*
     * const char
     */
    const char *const str = "hello world";
    cout << str << endl;


    return EXIT_SUCCESS;
}