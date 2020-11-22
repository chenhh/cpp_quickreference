#include <iostream>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xview.hpp>
#include <xtensor/xmath.hpp>
#include <fmt/core.h>

int main() {
    std::cout << "hello xtensor\n";
    xt::xarray<double> arr1
            {{1.0, 2.0, 3.0},
             {2.0, 5.0, 7.0},
             {2.0, 5.0, 7.0}};
    std::cout << arr1(0, 1) << std::endl;
    std::cout << arr1.at(0, 1) << std::endl;
    xt::xarray<double> arr2
            {5.0, 6.0, 7.0};

    xt::xarray<double> res = xt::view(arr1, 1) + arr2;

    std::cout << res << std::endl;
    std::cout << xt::sum(res) << std::endl;

    xt::xarray<int> arr
            {1, 2, 3, 4, 5, 6, 7, 8, 9};
    arr.reshape({3, 3});
    std::cout << arr << std::endl;
    fmt::print("arr value: {}", arr[2]);

    return 0;
}