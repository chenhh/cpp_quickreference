#include <vector>
#include "Poco/String.h"
#include "Poco/Format.h"

using Poco::cat;
using Poco::format;

int main(int argc, char **argv) {
    try {
        std::vector<std::string> colors;
        colors.push_back("red");
        colors.push_back("green");
        colors.push_back("blue");
        std::string str;
        str = cat(std::string(", "), colors.begin(), colors.end());
        // "red, green, blue"
        std::cout << str << std::endl;

        int n = 42;
        std::string s;
        format(s, "The answer to life, the universe and everything is %d", n);
        s = format("%d + %d = %d", 2, 2, 4); // "2 + 2 = 4"
        std::cout << s << std::endl;
        s = format("%4d", 42);               // "  42"
        std::cout << s << std::endl;
        s = format("%-4d", 42);              // "42  "
        std::cout << s << std::endl;
        format(s, "%d", std::string("foo")); // "[ERRFMT]"
        std::cout << s << std::endl;
    }
    catch (Poco::Exception &e) {
        std::string s = e.what();
        s += " " + e.message();
    }

    return 0;
}