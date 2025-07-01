#include<iostream>


class Solution {
public:
    int mySqrt(int x) {
        if ( x < 2) return x;
        int i = 1;

        while ((long long) i * i <= x){
            ++i;
        } 
        return i - 1;       
    }
};

int main() {
    Solution solution;
    
    // Test cases
    int test1 = 4;
    int test2 = 8;
    int test3 = 0;
    int test4 = 1;
    int test5 = 2147395599;  // A large number near sqrt(INT_MAX)

    std::cout << "mySqrt(" << test1 << ") = " << solution.mySqrt(test1) << std::endl;
    std::cout << "mySqrt(" << test2 << ") = " << solution.mySqrt(test2) << std::endl;
    std::cout << "mySqrt(" << test3 << ") = " << solution.mySqrt(test3) << std::endl;
    std::cout << "mySqrt(" << test4 << ") = " << solution.mySqrt(test4) << std::endl;
    std::cout << "mySqrt(" << test5 << ") = " << solution.mySqrt(test5) << std::endl;

    return 0;
}