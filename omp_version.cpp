#include <omp.h>
#include <iostream>

int main() {
    #pragma omp parallel
    {
        std::cout << "hello openMP" << std::endl;
    }

return 0;
}
