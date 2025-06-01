#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    int romanToInt(std::string s) {
        std::unordered_map<char, int> roman = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int total_value = 0;
        int prev_value = 0;

        for (int i = s.size() -1; i >= 0; --i){
            int current = roman[s[i]];
            if (current < prev_value) {
                total_value -= current;
            } else {
                total_value += current;
            }
            prev_value = current;
        }
        return total_value;
        
    }
};

int main() {
    Solution solution;

    std::string test1 = "III";
    std::string test2 = "LVIII";
    std::string test3 = "MCMXCIV";

    std::cout << "Roman numeral " << test1 << " = " << solution.romanToInt(test1) << std::endl;
    std::cout << "Roman numeral " << test2 << " = " << solution.romanToInt(test2) << std::endl;
    std::cout << "Roman numeral " << test3 << " = " << solution.romanToInt(test3) << std::endl;

    return 0;
}