#include <vector>
using namespace std;


class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }

    bool backtracking(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; ++c) {
                        if (isValid(i, j, c, board)) {
                            board[i][j] = c;
                            if (backtracking(board)) {
                                return true;
                            }
                        }
                        board[i][j] = '.'; 
                    }
                    return false; 
                }
            }
        }
        return true; 
    }
    
    bool isValid(int row, int col, char val, vector<vector<char>>& board) {
        //检查行
        for (int i = 0; i < 9; ++i) {
           if (board[row][i] == val) {
                return false; 
            }
        }
        //检查列
        for (int j = 0; j < 9; ++j) {
           if (board[j][col] == val) {
                return false; 
            }
        }
        //检查3x3子方格
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; ++i) {
            for (int j = startCol; j < startCol + 3; ++j) {
                if (board[i][j] == val) {
                    return false; 
                }
            }
        }
        return true;
    }
};