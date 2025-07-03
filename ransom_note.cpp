#include<iostream>
#include<string>
#include<vector>

class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        std::vector<int> count(26, 0);

        for (char c : magazine) {
            count[c - 'a']++;
        }

        for (char c : ransomNote) {
            if (count[c - 'a'] == 0) {
                return false; 
            }
            count[c - 'a']--;
        }

        return true;
    }
};

int main() {
    Solution sol;

    std::string ransomNote, magazine;

    // Example 1
    ransomNote = "a";
    magazine = "b";
    std::cout << "Can construct \"" << ransomNote << "\" from \"" << magazine << "\": "
         << (sol.canConstruct(ransomNote, magazine) ? "true" : "false") << std::endl;

    // Example 2
    ransomNote = "aa";
    magazine = "ab";
    std::cout << "Can construct \"" << ransomNote << "\" from \"" << magazine << "\": "
         << (sol.canConstruct(ransomNote, magazine) ? "true" : "false") << std::endl;

    // Example 3
    ransomNote = "aa";
    magazine = "aab";
    std::cout << "Can construct \"" << ransomNote << "\" from \"" << magazine << "\": "
         << (sol.canConstruct(ransomNote, magazine) ? "true" : "false") << std::endl;

    return 0;
}
