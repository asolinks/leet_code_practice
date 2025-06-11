#include<iostream>
#include<vector>
#include<string>

class Solution {
public:
    string longestCommonPrefix(std::vector<string>& strs) {
        if (strs.empty()) return "";

        std::string prefix = strs[0];

        for (int i = 1; i < strs.size(); ++i) {
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.length() - 1);
                if (prefix.empty()) return "";
            }
        }

        return prefix;
    }
};

int main() {
    Solution solution;

    // Test Case 1
    std::vector<std::string> strs1 = {"flower", "flow", "flight"};
    std::cout << "Common Prefix: " << solution.longestCommonPrefix(strs1) << std::endl;

    // Test Case 2
    std::vector<std::string> strs2 = {"dog", "racecar", "car"};
    std::cout << "Common Prefix: " << solution.longestCommonPrefix(strs2) << std::endl;

    // Test Case 3
    std::vector<std::string> strs3 = {"interspecies", "interstellar", "interstate"};
    std::cout << "Common Prefix: " << solution.longestCommonPrefix(strs3) << std::endl;

    // Test Case 4
    std::vector<std::string> strs4 = {""};
    std::cout << "Common Prefix: " << solution.longestCommonPrefix(strs4) << std::endl;

    // Test Case 5
    std::vector<std::string> strs5 = {"a"};
    std::cout << "Common Prefix: " << solution.longestCommonPrefix(strs5) << std::endl;

    return 0;
}