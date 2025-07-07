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

int main() {
    Solution solution;

    std::vector<std::string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};

    std::vector<std::vector<std::string>> output = solution.groupAnagrams(input);

    std::cout << "Grouped Anagrams:\n";
    for (const auto& group : output) {
        std::cout << "[ ";
        for (const auto& word : group) {
            std::cout << word << " ";
        }
        std::cout << "]\n";
    }

    return 0;
}