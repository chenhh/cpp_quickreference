#include <iostream>
#include <string>
#include <absl/container/btree_map.h>
#include <absl/container/btree_set.h>
#include <absl/container/flat_hash_map.h>
#include <absl/container/flat_hash_set.h>

void btree_example() {
    // Examples using btree_multimap and btree_multiset are equivalent

    // Default constructor
    // No allocation for the B-tree's elements is made.
    absl::btree_set<std::string> set1;
    absl::btree_map<int, std::string> map1;

    std::ostream_iterator<std::string> cout_it(std::cout, " ");
    // Initializer List constructor
    absl::btree_set<std::string> set2 = {{"huey"},
                                         {"dewey"},
                                         {"louie"},};
    std::copy(set2.begin(), set2.end(), cout_it);

    absl::btree_map<int, std::string> map2 =
            {{1, "huey"},
             {2, "dewey"},
             {3, "louie"},};
    for (auto it = map2.cbegin(); it != map2.cend(); ++it) {
        std::cout << it->first << " " << it->second << std::endl;
    }

    // Copy constructor
    absl::btree_set<std::string> set3(set2);
    absl::btree_map<int, std::string> map3(map2);

    // Copy assignment operator
    // Hash functor and Comparator are copied as well
    absl::btree_set<std::string> set4;
    set4 = set3;

    absl::btree_map<int, std::string> map4;
    map4 = map3;

    // Move constructor
    // Move is guaranteed efficient
    absl::btree_set<std::string> set5(std::move(set4));
    absl::btree_map<int, std::string> map5(std::move(map4));

    // Move assignment operator
    // May be efficient if allocators are compatible
    absl::btree_set<std::string> set6;
    set6 = std::move(set5);

    absl::btree_map<int, std::string> map6;
    map6 = std::move(map5);

    // Range constructor
    std::vector<std::string> v = {"a", "b"};
    absl::btree_set<std::string> set7(v.begin(), v.end());

    std::vector<std::pair<int, std::string> > v2 = {{1, "a"},
                                                    {2, "b"}};
    absl::btree_map<int, std::string> set8(v2.begin(), v2.end());
}

void hash_example() {
    // Examples using node_hash_set and node_hash_map are equivalent

    // Default constructor
    // No allocation for the table's elements is made.
    absl::flat_hash_set<std::string> set1;
    absl::flat_hash_map<int, std::string> map1;

    // Initializer List constructor
    absl::flat_hash_set<std::string> set2 = {{"huey"},
                                             {"dewey"},
                                             {"louie"},};
    absl::flat_hash_map<int, std::string> map2 =
            {{1, "huey"},
             {2, "dewey"},
             {3, "louie"},};

    // Copy constructor
    absl::flat_hash_set<std::string> set3(set2);
    absl::flat_hash_map<int, std::string> map3(map2);

    // Copy assignment operator
    // Hash functor and Comparator are copied as well
    absl::flat_hash_set<std::string> set4;
    set4 = set3;

    absl::flat_hash_map<int, std::string> map4;
    map4 = map3;

    // Move constructor
    // Move is guaranteed efficient
    absl::flat_hash_set<std::string> set5(std::move(set4));
    absl::flat_hash_map<int, std::string> map5(std::move(map4));

    // Move assignment operator
    // May be efficient if allocators are compatible
    absl::flat_hash_set<std::string> set6;
    set6 = std::move(set5);

    absl::flat_hash_map<int, std::string> map6;
    map6 = std::move(map5);

    // Range constructor
    std::vector<std::string> v = {"a", "b"};
    absl::flat_hash_set<std::string> set7(v.begin(), v.end());

    std::vector<std::pair<int, std::string>> v2 = {{1, "a"},
                                                   {2, "b"}};
    absl::flat_hash_map<int, std::string> set8(v2.begin(), v2.end());
}


int main() {
    btree_example();
    hash_example();
    return 0;
}