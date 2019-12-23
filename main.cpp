//
// Created by chen1 on 2019/12/23.
//

#include <iostream>
#include <cstdlib>
#include <gmpxx.h>

int main() {
    std::cout << "hello world" << std::endl;

    mpz_class a, b, c;
    a = 1234;
    b = "-5678";
    c = a+b;
    std::cout << "sum is " << c << "\n";
    std::cout << "absolute value is " << abs(c) << "\n";
    return EXIT_SUCCESS;
}

