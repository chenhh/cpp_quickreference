//
// Created by chen1 on 2020/11/23.
//
#include <pprint.hpp>
#include <sstream>
#include <iostream>

void basic_example() {
    // out for a string
    // std::stringstream stream;
    // pprint::PrettyPrinter printer(stream);
    pprint::PrettyPrinter printer(std::cout);
    printer.print(5);
    printer.print(3.14f);
    printer.print(2.718);
    printer.print(true);
    printer.print('x');
    printer.print("Hello, world");
    printer.print(nullptr);

    printer.quotes(true);
    printer.print("A", "B", "C");
    printer.quotes(false);

    using namespace std::complex_literals;
    std::complex<double> foo = 1. + 2.5i;
    std::complex<double> bar = 9. + 4i;
    printer.print(foo, "*", bar, "=", (foo * bar));   // parameter packing

    enum Color {
        RED = 2, BLUE = 4, GREEN = 8
    };
    Color color = BLUE;
    printer.print(color);

    typedef std::array<std::array<int, 3>, 3> Mat3x3;
    Mat3x3 matrix;
    matrix[0] = {1, 2, 3};
    matrix[1] = {4, 5, 6};
    matrix[2] = {7, 8, 9};
    printer.print("Matrix =", matrix);

    std::vector<std::map<std::string, int>> foo2{
            {{"a", 1}, {"b", 2}},
            {{"c", 3}, {"d", 4}}};
    printer.compact(true);
    printer.print("Foo2 =", foo2);

    printer.print(std::map<std::string, std::set<int>>{
            {"foo", {1, 2, 3, 3, 2, 1}},
            {"bar", {7, 6, 5, 4}}});

    std::priority_queue<int> queue;
    for (int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
        queue.push(n);
    printer.print(queue);

    auto get_student = [](int id) {
        if (id == 0) return std::make_tuple(3.8, 'A', "Lisa Simpson");
        if (id == 1) return std::make_tuple(2.9, 'C', "Milhouse Van Houten");
        if (id == 2) return std::make_tuple(1.7, 'D', "Ralph Wiggum");
        throw std::invalid_argument("id");
    };
    printer.print({get_student(0), get_student(1), get_student(2)});

    class Foo {
    };
    Foo foo3;
    printer.print(foo3);
}

int main() {
    basic_example();
    return 0;
}

