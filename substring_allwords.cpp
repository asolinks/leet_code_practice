#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<unordered_map>

class Solution {
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
        std::vector<int> result;
        if (words.empty() || s.empty()) return result;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        if (s.size() < totalLen) return result;

        std::unordered_map<std::string, int> wordFreq;
        for (const auto& word : words) {
            wordFreq[word]++;
        }

        for (int i = 0; i < wordLen; ++i) {
            int left = i, right = i, count = 0;
            std::unordered_map<std::string, int> window;

            while (right + wordLen <= s.size()) {
                std::string word = s.substr(right, wordLen);
                right += wordLen;

                if (wordFreq.count(word)) {
                    window[word]++;
                    count++;

                    while (window[word] > wordFreq[word]) {
                        std::string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    if (count == wordCount) {
                        result.push_back(left);
                    }
                } else {
                    window.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};
