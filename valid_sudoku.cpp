#include<iostream>
#include<vector>
#include<unordered_set>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        std::unordered_set<std::string> seen;

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char val = board[i][j];
                if (val != '.') {
                    std::string rowKey = std::string(1, val) + " in row " + std::to_string(i);
                    std::string colKey = std::string(1, val) + " in col " + std::to_string(j);
                    std::string boxKey = std::string(1, val) + " in box " + std::to_string(i / 3) + "-" + std::to_string(j / 3);

                    if (seen.count(rowKey) || seen.count(colKey) || seen.count(boxKey)) {
                        return false;
                    }

                    seen.insert(rowKey);
                    seen.insert(colKey);
                    seen.insert(boxKey);
                }
            }
        }

        return true;
    }
};

int main() {
    std::vector<std::vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Solution solution;
    bool result = solution.isValidSudoku(board);
    std::cout << (result ? "Valid Sudoku" : "Invalid Sudoku") << std::endl;

    return 0;
}