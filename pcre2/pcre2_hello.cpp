#include <iostream>
#include <chrono>
#define PCRE2_STATIC
#define PCRE2_CODE_UNIT_WIDTH 8
#include "pcre2.h"

using namespace std;
using namespace std::chrono;
using namespace std::chrono_literals;

int main()
{
    auto start = high_resolution_clock::now();
    int errn;
    PCRE2_SIZE erroffset;
    auto pattern = (PCRE2_SPTR8)"^[\\w._]+@\\w+\\.[a-zA-Z]+$";
    pcre2_code* re = pcre2_compile(pattern, PCRE2_ZERO_TERMINATED, 0, &errn, &erroffset, nullptr);
    if (!re)
        cerr << "pcre2_compile failed\n";
    pcre2_match_data* match_data = pcre2_match_data_create_from_pattern(re, nullptr);
    for (long i = 0; i < 1000000; i++) {
        auto text = (PCRE2_SPTR8)"abcd_ed123.t12y@haha.com";
        int rc = pcre2_match(re, text, PCRE2_ZERO_TERMINATED, 0, 0, match_data, nullptr);
        if (rc <= 0)
            cerr << "pcre2_match failed\n";
    }
    auto end = high_resolution_clock::now();
    cout << (end - start) / 1ms << "\n";
    return 0;
}