#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include<iostream>

class Solution {
public:
    bool wordPattern(std::string pattern, std::string s) {
        std::vector<std::string> words;
        std::string word;
        std::istringstream iss(s);

        while (iss >> word) {
            words.push_back(word);
        }
        
        if (words.size() != pattern.size()) {
            return false;
        }

        std::unordered_map<char, std::string> charToWord;
        std::unordered_map<std::string, char> wordToChar;

        for (int i = 0; i < pattern.size(); ++i) {
            char c = pattern[i];
            std::string w = words[i];

            if (charToWord.count(c)) {
                if (charToWord[c] != w) return false;
            } else {
                charToWord[c] = w;
            }

            if (wordToChar.count(w)) {
                if (wordToChar[w] != c) return false;
            } else {
                wordToChar[w] = c;
            }
        }
        
        return true;
    }
};


int main() {
    Solution solution;

    std::string pattern1 = "abba";
    std::string s1 = "dog cat cat dog";
    std::cout << std::boolalpha << solution.wordPattern(pattern1, s1) << "\n";  // Expected: true

    std::string pattern2 = "abba";
    std::string s2 = "dog cat cat fish";
    std::cout << std::boolalpha << solution.wordPattern(pattern2, s2) << "\n";  // Expected: false

    std::string pattern3 = "aaaa";
    std::string s3 = "dog cat cat dog";
    std::cout << std::boolalpha << solution.wordPattern(pattern3, s3) << "\n";  // Expected: false

    return 0;
}