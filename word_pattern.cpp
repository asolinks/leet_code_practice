#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

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
