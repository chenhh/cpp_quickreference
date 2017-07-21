#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    /*
     * const variable, it cannot be changed.
     */
    const int v1 = 10;
    // v1 = 20; error
    cout<<"const variable v1="<<v1<<endl;
    
    /*
     * reference to const variable
     */
    // int &v2 = v1; error
    const int& v2 = v1;
    // v2 = 20; error
    cout<<"const reference to v1, v2="<<v2<<endl;


    /*
     * const pointer to a const variable
     */
    const int* const p1 = &v1;
    cout<<"const pointer to a const variable, p1="<<*p1<<endl;


    /*
     * const char
     */
    char* const str="hello world";
    cout<<str<<endl;


    return EXIT_SUCCESS;
}