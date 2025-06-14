#include<iostream>
#include<string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        int pos = haystack.find(needle);
        return pos == std::string::npos ? -1 : static_cast<int>(pos);
    }
};

int main() {
    Solution solution;

    // Test cases
    std::string haystack1 = "sadbutsad";
    std::string needle1 = "sad";
    std::cout << "Test 1: " << solution.strStr(haystack1, needle1) << std::endl; // Expected: 0

    std::string haystack2 = "leetcode";
    std::string needle2 = "leeto";
    std::cout << "Test 2: " << solution.strStr(haystack2, needle2) << std::endl; // Expected: -1

    std::string haystack3 = "hello";
    std::string needle3 = "ll";
    std::cout << "Test 3: " << solution.strStr(haystack3, needle3) << std::endl; // Expected: 2

    std::string haystack4 = "abc";
    std::string needle4 = "";
    std::cout << "Test 4: " << solution.strStr(haystack4, needle4) << std::endl; // Expected: 0

    return 0;
}