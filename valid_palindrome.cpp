#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

class Solution {
public:
    bool isPalindrome(std::string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            
            while (left < right && !isalnum(s[right])) {
                right--;
            }

            
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};

int main() {
    Solution solution;
    
    std::string test1 = "A man, a plan, a canal: Panama";
    std::string test2 = "race a car";
    std::string test3 = " ";

    std::cout << "Test 1: " << (solution.isPalindrome(test1) ? "true" : "false") << std::endl;
    std::cout << "Test 2: " << (solution.isPalindrome(test2) ? "true" : "false") << std::endl;
    std::cout << "Test 3: " << (solution.isPalindrome(test3) ? "true" : "false") << std::endl;

    return 0;
}
