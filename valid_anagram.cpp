#include<iostream>
#include<string>
#include<vector>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.length() != t.length()) return false;

        std::vector<int> count(26, 0);

        for (int i = 0; i < s.length(); ++i) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for (int c : count) {
            if (c != 0) return false;
        }

        return true;
    }
};

int main() {
    Solution solution;

    std::string s1 = "anagram";
    std::string t1 = "nagaram";
    std::cout << "Is \"" << t1 << "\" an anagram of \"" << s1 << "\"? "
         << (solution.isAnagram(s1, t1) ? "True" : "False") << std::endl;

    std::string s2 = "rat";
    std::string t2 = "car";
    std::cout << "Is \"" << t2 << "\" an anagram of \"" << s2 << "\"? "
         << (solution.isAnagram(s2, t2) ? "True" : "False") << std::endl;

    return 0;
}