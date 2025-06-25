#include <unordered_map>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        if (s.size() < t.size()) return "";

        std::unordered_map<char, int> t_freq, window_freq;
        for (char c : t) t_freq[c]++;

        int required = t_freq.size(); 
        int formed = 0; 

        int l = 0, r = 0;
        int min_len = INT_MAX, min_start = 0;

        while (r < s.size()) {
            char c = s[r];
            window_freq[c]++;

            if (t_freq.count(c) && window_freq[c] == t_freq[c]) {
                formed++;
            }

            while (l <= r && formed == required) {
                if (r - l + 1 < min_len) {
                    min_len = r - l + 1;
                    min_start = l;
                }

                char left_char = s[l];
                window_freq[left_char]--;
                if (t_freq.count(left_char) && window_freq[left_char] < t_freq[left_char]) {
                    formed--;
                }
                l++;
            }

            r++;
        }

        return min_len == INT_MAX ? "" : s.substr(min_start, min_len);
    }
};


int main() {
    Solution solution;

    string s1 = "ADOBECODEBANC", t1 = "ABC";
    string result1 = solution.minWindow(s1, t1);
    cout << "Input: s = \"" << s1 << "\", t = \"" << t1 << "\"\n";
    cout << "Output: \"" << result1 << "\"\n\n";

    string s2 = "a", t2 = "a";
    string result2 = solution.minWindow(s2, t2);
    cout << "Input: s = \"" << s2 << "\", t = \"" << t2 << "\"\n";
    cout << "Output: \"" << result2 << "\"\n\n";

    string s3 = "a", t3 = "aa";
    string result3 = solution.minWindow(s3, t3);
    cout << "Input: s = \"" << s3 << "\", t = \"" << t3 << "\"\n";
    cout << "Output: \"" << result3 << "\"\n";

    return 0;
}