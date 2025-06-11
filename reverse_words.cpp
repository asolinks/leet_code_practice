#include<sstream>
#include<algorithm>
#include<vector>

class Solution {
public:
    string reverseWords(string s) {
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