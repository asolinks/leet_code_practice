#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    	std::unordered_map<std::string, std::vector<string>> anagramGroups;

    	for (std::string& word : strs){
    		std::string sortedWord = word;
    		sort(sortedWord.begin(), sortedWord.end());
    		anagramGroups[sortedWord].push_back(word);
    	}

    	std::vector<vector<string>> result;
    	for(auto& entry : anagramGroups){
    		result.push_back(entry.second);
    	}
    	return result;
        
    }
};