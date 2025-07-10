#include<iostream>
#include<vector>
#include<unordered_set>

class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set<int> seen;

        while (n != 1 && !seen.count(n)){
        	seen.insert(n);
        	n = getNext(n);
        }
        return n == 1;
    }

private:
	int getNext(int n){
		int totalSum = 0;
		while (n > 0){
			int digit = n % 10;
			totalSum += digit * digit;
			n /= 10;
		}
		return totalSum;
	}
};

int main() {
    Solution solution;
    
    std::vector<int> testCases = {19, 2, 7, 20}; 
    
    for (int n : testCases) {
        bool result = solution.isHappy(n);
        std::cout << "Is " << n << " a happy number? " << (result ? "Yes" : "No") << std::endl;
    }

    return 0;
}