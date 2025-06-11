#include<iostream>
#include<sstream>
#include<algorithm>
#include<vector>

class Solution {
public:
    std::string reverseWords(std::string s) {
    	std::istringstream tokenize (s);
    	std::vector<std::string> words;
    	std::string word, result;

    	while(tokenize >> word){
    		words.push_back(word);
    	}

    	reverse(words.begin(), words.end());

    	for (int i = 0; i < words.size(); ++i){
    		result += words[i];
    		if(i != words.size() - 1) result += ' ';
    	}
    	return result;        
    }
};

int main() {
    Solution sol;

    std::string input1 = "the sky is blue";
    std::string input2 = "  hello world  ";
    std::string input3 = "a good   example";

    std::cout << "Input: \"" << input1 << "\"\n";
    std::cout << "Output: \"" << sol.reverseWords(input1) << "\"\n\n";

    std::cout << "Input: \"" << input2 << "\"\n";
    std::cout << "Output: \"" << sol.reverseWords(input2) << "\"\n\n";

    std::cout << "Input: \"" << input3 << "\"\n";
    std::cout << "Output: \"" << sol.reverseWords(input3) << "\"\n\n";

    return 0;
}