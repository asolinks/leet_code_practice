#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if( numRows == 1 || s.size() < numRows) return s;

        std::vector<std:: string> rows(std::min(numRows, (int)s.size()));
        int currRow = 0;
        bool goingDown = false;

        for (int c : s){
            rows[currRow] += c;
            if (currRow == 0 || currRow == numRows -1)
                goingDown = !goingDown;

            currRow += goingDown ? 1 : -1;
        }

        std:: string result;
        for (std::string& row : rows){
            result += row;
        }
        return result;

        
    }
};