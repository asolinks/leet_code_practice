#include <iostream>
#include <string>

class Solution {
public:
    int hIndex(std::vector<int>& citations) {
    	std::sort(citations.begin(), citations.end(), std::greater<int>());
    	int h = 0;

    	for (int i = 0; i < citations.size(); ++i){
    		if (citations[i] >= i + 1){
    			h = i + 1;
    		} else {
    			break;
    		}
    	}
    	return h;
        
    }
};

int main() {
    std::vector<int> citations = {3, 0, 6, 1, 5};
    
    Solution sol;
    int h_index = sol.hIndex(citations);

    std::cout << "The h-index is: " << h_index << std::endl;

    return 0;
}