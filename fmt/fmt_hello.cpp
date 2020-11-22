#include <iostream>
#include <cstdlib>
#include <string>
#include <fmt/core.h>

int main(){
    std::string message = fmt::format("The answer is {}\n", 42);
    fmt::print(message);

    fmt::print("Don't {}\n", "panic");
    fmt::print("I'd rather be {1} than {0}.", "right", "happy");
    fmt::print("Hello, {name}! The answer is {number}. Goodbye, {name}.",
               fmt::arg("name", "World"),
               fmt::arg("number", 42));

    // rhrows a format_error exception with description “unknown format
    // code ‘d’ for string”
    // fmt::format("The answer is {:d}", "forty-two");

    // wide format string
    fmt::format(L"Cyrillic letter {}", L'\x42e');

    fmt::print("Elapsed time: {0:.2f} seconds", 1.23);

    return 0;
}