#include<iostream>
#include<string>

class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
    	int i = 0, j = 0;

    	while(i < s.size() && j < t.size()){
    		if(s[i] == t[j]){
    			i++;
    		}
    		j++;
    	}
    	return i == s.size();
        
    }
};

int main() {
    Solution solution;

    // Test case 1
    std::string s1 = "abc";
    std::string t1 = "ahbgdc";
    std::cout << "Input: s = \"" << s1 << "\", t = \"" << t1 << "\"\n";
    std::cout << "Output: " << (solution.isSubsequence(s1, t1) ? "true" : "false") << "\n\n";

    // Test case 2
    std::string s2 = "axc";
    std::string t2 = "ahbgdc";
    std::cout << "Input: s = \"" << s2 << "\", t = \"" << t2 << "\"\n";
    std::cout << "Output: " << (solution.isSubsequence(s2, t2) ? "true" : "false") << "\n\n";

    // Custom test case
    std::string s3 = "ace";
    std::string t3 = "abcde";
    std::cout << "Input: s = \"" << s3 << "\", t = \"" << t3 << "\"\n";
    std::cout << "Output: " << (solution.isSubsequence(s3, t3) ? "true" : "false") << "\n";

    return 0;
}