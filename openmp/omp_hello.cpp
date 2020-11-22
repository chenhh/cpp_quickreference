#include <omp.h>
#include <iostream>

void Hello() {
    int my_rank = omp_get_thread_num();
    int thread_count = omp_get_num_threads();
    std::cout << "hello from thread " << my_rank
              << " of " << thread_count << std::endl;
}

int main() {
#pragma omp parallel num_threads(4)
    Hello();
    return 0;
}
