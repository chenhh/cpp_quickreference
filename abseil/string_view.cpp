#include <iostream>
#include <string>
#include <absl/strings/string_view.h>

void string_view_basic() {
    std::string s{"Tired like a dog"};
    /* 用 std::string 初始化 */
    absl::string_view sv(s);

    const char *cs = "Hello world";
    /* 用字串指標初始化 */
    absl::string_view sv1(cs);

    /* 用字串區間初始化，輸出 "world" */
    absl::string_view sv2(cs + 6, 5);

    /* string_view 會自動判斷字串結尾，不會溢位，同樣輸出 "world" */
    absl::string_view sv3(cs + 6, 8);

    absl::string_view sv4;
    sv4 = sv3;   /* string_view 之間可以直接賦值 */

    std::cout << sv << std::endl; // Tired like a dog
    std::cout << sv1 << std::endl; // Hello world
    std::cout << sv2 << std::endl; // world
    std::cout << sv3 << std::endl; // world s
    std::cout << sv4 << std::endl; // world s

    /* 可以用方括號獲取string_view 中的字元 */
    std::cout << sv4[2] << std::endl;
    /* ERROR：不允許通過方括號更改底層字元，因為string_view 不持有底層字元 */
    //    sv4[2]  = 'i';
}

void string_view_iterator() {
    std::string s{"Tired like a dog"};
    absl::string_view sv(s);

    // forward iterator
    for (auto it = sv.begin(); it != sv.end(); ++it) {
        std::cout << *it << std::endl;
        // cannot modify sv data
        // *it = 'h;
    }

    // reverse iterator
    std::cout << "----------" << std::endl;
    for (auto it = sv.rbegin(); it != sv.rend(); ++it) {
        std::cout << *it << std::endl;
    }
    std::cout << "----------" << std::endl;

    // const forward iterator
    const absl::string_view csv(sv);
    for (auto it = csv.cbegin(); it != csv.cend(); ++it) {
        std::cout << *it << std::endl;
    }

    // const reverse iterator
    std::cout << "----------" << std::endl;
    for (auto it = csv.crbegin(); it != csv.crend(); ++it) {
        std::cout << *it << std::endl;
    }
}

void string_view_function() {
    absl::string_view sv1;
    if (sv1.empty()) std::cout << "sv1 is empty" << std::endl;

    const char *cs = "Tired like a dog";
    absl::string_view sv(cs + 6);
    /* 輸出 ”like a dog"，即string_view 指向的區間 */
    std::cout << sv.data() << std::endl;
    /* 輸出指向的區間長度 */
    std::cout << sv.length() << std::endl;
    // the same as length
    std::cout << sv.size() << std::endl;
    /* 輸出子區間首字元 'l' */
    std::cout << sv.front() << std::endl;
    /* 輸出子區間尾字元 'g' */
    std::cout << sv.back() << std::endl;
}

void string_view_prefix_suffix() {
    /* 這裡移除字首和字尾並不會更改string_view 指向的底層資料，
     * 這二者只是移動了string_view 內部的頭部和尾部指標，
     * 並修改了 string_view 的長度，並未對底層資料作任何改動。
     * */
    const char *cs = "Tired like a dog";

    /* 用 std::string 初始化 */
    absl::string_view sv(cs);
    /* 移除 sv 中從頭開始的6個字元 "Tired "，底層字串不變 */
    sv.remove_prefix(6);
    /* 輸出 "like a dog" */
    std::cout << sv << std::endl;

    /* 移除 sv 中從結尾開始的4個字元 " dog"，底層字串不變 */
    sv.remove_suffix(4);
    /* 輸出 "like a" */
    std::cout << sv << std::endl;
    // "Tired like a dog"
    std::cout << cs << std::endl;

    /* ERROR: 超過當前 sv 長度，執行時報錯 */
//    sv.remove_suffix(20);
}

void string_view_copy_substr() {
    const char *cs{"Tired like a dog"};
    absl::string_view sv(cs);

    const char *cs1{"hello world"};
    absl::string_view sv1(cs1);
    /* 獲取子字串，長度超過末尾會截止到末尾處 */
    absl::string_view sv2 = sv1.substr(6, 10);

    char carr[10] = {0};
    /* 從 sv1 的索引為6的位置開始複製 4個字元到 carr 中 */
    sv1.copy(carr, 4, 6);
    std::cout << "copy carr:" << sv1 << std::endl;
    /* 從 sv1 的索引為6的位置開始複製 8 個字元到 carr 中，但由於超過末尾，只複製
     *  到sv1 的末尾
     */

    /* sv1.copy(carr, 4, 25); // ERROR: 指定的位置超出了 sv 末尾，執行時報錯 */
    sv1.copy(carr, 8, 6);
    std::cout << "copy carr:" << sv1 << std::endl;

    /* 交換兩個 string_view 型別的變數，底層資料不變 */
    sv1.swap(sv);
    std::cout << "swap sv:" << sv1 << std::endl;
}

void string_view_compare() {
    /* string_view 的比較和字串比較函式 strcmp 的行為比較類似，
     * 執行字典序比較。比較結果為小於時返回 -1， 等於時返回 0， 大於時返回 1
     * */
    absl::string_view sv{"hello"};
    absl::string_view sv1{"world"};

    if (sv.compare(sv1) < 0) {
        std::cout << "hello" << std::endl;
    }

    /* 比較從位置3開始的兩個字元子串與 sv1 的大小 */
    sv.compare(3, 2, sv1);
    /* 比較 sv 和 sv1 的兩個子串，子串用位置和長度表示 */
    sv.compare(3, 2, sv1, 1, 3);
    /* sv 與 const char* 型比較 */
    sv.compare("hello");
    /* 將sv子串與 const char* 型比較 */
    sv.compare(3, 2, "hello");
    /* 將sv子串與 const char* 型從頭開始的子串比較, 4 是長度 */
    sv.compare(3, 2, "hello", 4);

}

int main() {
    string_view_basic();
    std::cout << std::string(50, '*') << std::endl;
    string_view_iterator();
    std::cout << std::string(50, '*') << std::endl;
    string_view_function();
    std::cout << std::string(50, '*') << std::endl;
    string_view_prefix_suffix();
    std::cout << std::string(50, '*') << std::endl;
    string_view_copy_substr();
    std::cout << std::string(50, '*') << std::endl;
    string_view_compare();
    std::cout << std::string(50, '*') << std::endl;
    return 0;
}