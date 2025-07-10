//59. 螺旋矩阵 II
//https://leetcode.cn/problems/spiral-matrix-ii/description/

#include <iostream>
#include <vector>
using namespace std;

class Spiral_martrix{
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n,0));  // 初始化 n×n 矩阵
        int startX = 0;
        int startY = 0;
        int count = 1;
        int i = 0;
        int j = 0;
        int offset = 0;
        int circle_num = n/2;
        while (circle_num--) {
            for (; j < n - 1 - offset; j++) {
                matrix[i][j] = count++;
            }
            for (; i < n - 1 - offset; i++) {
                matrix[i][j] = count++;
            }
            for (; j > 0 + offset; j--) {
                matrix[i][j] = count++;
            }
            for (; i > 0 + offset; i--) {
                matrix[i][j] = count++;
            }
            startX++;
            startY++;
            offset++;
            j = startX;
            i = startY;
        }
        if (n % 2 != 0) {
                matrix[i][j] = count;
        }
        return matrix;
    }
};
