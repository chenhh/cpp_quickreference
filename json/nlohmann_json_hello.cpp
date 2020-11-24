// https://github.com/nlohmann/json
#include <nlohmann/json.hpp>
#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <array>
#include <forward_list>
#include <unordered_map>
#include <unordered_set>

// for convenience
using json = nlohmann::json;

void json_create() {
    // create an empty structure (null)
    json j;

// add a number that is stored as double (note the implicit conversion of j to an object)
    j["pi"] = 3.141;

// add a Boolean that is stored as bool
    j["happy"] = true;

// add a string that is stored as std::string
    j["name"] = "Niels";

// add another null object by passing nullptr
    j["nothing"] = nullptr;

// add an object inside the object
    j["answer"]["everything"] = 42;

// add an array that is stored as std::vector (using an initializer list)
    j["list"] = {1, 0, 2};

// add another object (using an initializer list of pairs)
    j["object"] = {{"currency", "USD"},
                   {"value",    42.99}};

// instead, you could also write (which looks very similar to the JSON above)
    json j2 = {
            {"pi",      3.141},
            {"happy",   true},
            {"name",    "Niels"},
            {"nothing", nullptr},
            {"answer",  {
                                {"everything", 42}
                        }},
            {"list",    {       1, 0, 2}},
            {"object",  {
                                {"currency",   "USD"},
                                   {"value", 42.99}
                        }}
    };

    std::cout << j << std::endl;
    std::cout << j2 << std::endl;
}

void json_serialization() {
    // create object from string literal
    json j = "{ \"happy\": true, \"pi\": 3.141 }"_json;

    // or even nicer with a raw string literal
    auto j2 = R"(
      {
        "happy": true,
        "pi": 3.141
      }
    )"_json;

    // parse explicitly
    auto j3 = json::parse("{ \"happy\": true, \"pi\": 3.141 }");

    for (auto &js : {j, j2, j3}) {
        std::cout << js << std::endl;
    }

    // explicit conversion to string
    std::string s = j.dump();    // {"happy":true,"pi":3.141}

    // serialization with pretty printing
    // pass in the amount of spaces to indent
    std::cout << j.dump(4) << std::endl;
    // {
    //     "happy": true,
    //     "pi": 3.141
    // }

}

void STL_like_access() {
    json j;
    j.push_back("foo");
    j.push_back(1);
    j.push_back(true);

    // also use emplace_back
    j.emplace_back(1.78);

    std::cout << "struct of json: " << j << std::endl;
    // iterate the array
    for (json::iterator it = j.begin(); it != j.end(); ++it) {
        std::cout << *it << '\n';
    }

    // range-based for
    for (auto &element : j) {
        std::cout << element << '\n';
    }

    // getter/setter
    const auto tmp = j[0].get<std::string>();
    j[1] = 42;
    bool foo = j.at(2);

    // comparison
    j == "[\"foo\", 42, true]"_json;  // true

    // other stuff
    j.size();     // 3 entries
    j.empty();    // false
    j.type();     // json::value_t::array
    j.clear();    // the array is empty again

    // convenience type checkers
    j.is_null();
    j.is_boolean();
    j.is_number();
    j.is_object();
    j.is_array();
    j.is_string();

    // create an object
    json o;
    o["foo"] = 23;
    o["bar"] = false;
    o["baz"] = 3.141;

    // also use emplace
    o.emplace("weather", "sunny");

    // special iterator member functions for objects
    for (json::iterator it = o.begin(); it != o.end(); ++it) {
        std::cout << it.key() << " : " << it.value() << "\n";
    }

    // the same code as range for
    for (auto &el : o.items()) {
        std::cout << el.key() << " : " << el.value() << "\n";
    }

    // even easier with structured bindings (C++17)
    for (auto&[key, value] : o.items()) {
        std::cout << key << " : " << value << "\n";
    }

    // find an entry
    if (o.contains("foo")) {
        // there is an entry with key "foo"
    }

    // or via find and an iterator
    if (o.find("foo") != o.end()) {
        // there is an entry with key "foo"
    }

    // or simpler using count()
    int foo_present = o.count("foo"); // 1
    int fob_present = o.count("fob"); // 0

    // delete an entry
    o.erase("foo");
}

void from_container() {
    std::vector<int> c_vector{1, 2, 3, 4};
    json j_vec(c_vector);
// [1, 2, 3, 4]

    std::deque<double> c_deque{1.2, 2.3, 3.4, 5.6};
    json j_deque(c_deque);
// [1.2, 2.3, 3.4, 5.6]

    std::list<bool> c_list{true, true, false, true};
    json j_list(c_list);
// [true, true, false, true]

    std::forward_list<int64_t> c_flist{12345678909876, 23456789098765, 34567890987654,
                                       45678909876543};
    json j_flist(c_flist);
// [12345678909876, 23456789098765, 34567890987654, 45678909876543]

    std::array<unsigned long, 4> c_array{{1, 2, 3, 4}};
    json j_array(c_array);
// [1, 2, 3, 4]

    std::set<std::string> c_set{"one", "two", "three", "four", "one"};
    json j_set(c_set); // only one entry for "one" is used
// ["four", "one", "three", "two"]

    std::unordered_set<std::string> c_uset{"one", "two", "three", "four", "one"};
    json j_uset(c_uset); // only one entry for "one" is used
// maybe ["two", "three", "four", "one"]

    std::multiset<std::string> c_mset{"one", "two", "one", "four"};
    json j_mset(c_mset); // both entries for "one" are used
// maybe ["one", "two", "one", "four"]

    std::unordered_multiset<std::string> c_umset{"one", "two", "one", "four"};
    json j_umset(c_umset); // both entries for "one" are used
// maybe ["one", "two", "one", "four"]
}

int main() {
    json_create();
    std::cout << std::string(50, '*') << std::endl;
    json_serialization();
    std::cout << std::string(50, '*') << std::endl;
    STL_like_access();
    std::cout << std::string(50, '*') << std::endl;
    from_container();
    return 0;
}
