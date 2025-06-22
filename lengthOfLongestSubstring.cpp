#include<iostream>
#include<unordered_set>
#include<string>
#include<algorithm>

class Solution{
public:
	int lengthOfLongestSubstring (std::string s) {
		std::unordered_set<char> chars;
		int left = 0, right = 0, maxLength = 0;

		while (right < s.size()){
			if (chars.find(s[right]) == chars.end()){
				chars.insert(s[right]);
				maxLength = std::max(maxLength, right - left + 1);
				right++;
			} else {
				chars.erase(left);
				left++;
			}
		}
		return maxLength;
	}
};

int main() {
    Solution solution;

    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    int result = solution.lengthOfLongestSubstring(input);
    std::cout << "Length of the longest substring without repeating characters: " << result << std::endl;

    return 0;
}