#include<iostream>
#include<string>
#include<vector>

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> count(26, 0);

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

    string ransomNote, magazine;

    // Example 1
    ransomNote = "a";
    magazine = "b";
    cout << "Can construct \"" << ransomNote << "\" from \"" << magazine << "\": "
         << (sol.canConstruct(ransomNote, magazine) ? "true" : "false") << endl;

    // Example 2
    ransomNote = "aa";
    magazine = "ab";
    cout << "Can construct \"" << ransomNote << "\" from \"" << magazine << "\": "
         << (sol.canConstruct(ransomNote, magazine) ? "true" : "false") << endl;

    // Example 3
    ransomNote = "aa";
    magazine = "aab";
    cout << "Can construct \"" << ransomNote << "\" from \"" << magazine << "\": "
         << (sol.canConstruct(ransomNote, magazine) ? "true" : "false") << endl;

    return 0;
}
