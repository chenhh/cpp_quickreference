#include <chrono>
#include <iostream>

int main() {
    using timepoint = std::chrono::time_point<std::chrono::high_resolution_clock>;

    auto print_exec_time = [](timepoint start, timepoint stop) {
        auto duration_us = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        auto duration_ms = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        auto duration_s = std::chrono::duration_cast<std::chrono::seconds>(stop - start);

        std::cout << duration_us.count() << " us | " << duration_ms.count() << " ms | "
                  << duration_s.count() << " s\n";
    };

    auto start = std::chrono::high_resolution_clock::now();

    auto stop = std::chrono::high_resolution_clock::now();

    print_exec_time(start, stop);
}