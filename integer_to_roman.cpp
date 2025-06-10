#include <iostream>
#include <string>
#include <vector>
#include <utility>

class Solution {
public:
    std::string intToRoman(int num) {
        std::vector<std::pair<int, std::string>> roman = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
        };

        std::string output;
        for (const auto& [value, symbol] : roman){
            while (num >= value){
                output += symbol;
                num -= value;
            }
        }
        return output;
        
    }
};

int main() {
    Solution sol;
    int number = 3749;

    std::string romanNumeral = sol.intToRoman(number);
    std::cout << "The Roman numeral for " << number << " is " << romanNumeral << std::endl;

    return 0;
}