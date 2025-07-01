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