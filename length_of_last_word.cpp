#include<iostream>
#include<vector>
#include <algorithm>  // for std::sort
#include <cassert>    // for assert

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        int length = 0;
        int i = s.length() - 1;

        // Skip trailing spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // Count the length of the last word
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
    }
};

int main() {
    Solution solution;

    std::string test1 = "Hello World";
    std::string test2 = "   fly me   to   the moon  ";
    std::string test3 = "luffy is still joyboy";

    std::cout << "Test 1: " << solution.lengthOfLastWord(test1) << std::endl;  // Output: 5
    std::cout << "Test 2: " << solution.lengthOfLastWord(test2) << std::endl;  // Output: 4
    std::cout << "Test 3: " << solution.lengthOfLastWord(test3) << std::endl;  // Output: 6

    return 0;
}