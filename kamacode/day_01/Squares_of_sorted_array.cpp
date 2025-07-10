//977. 有序数组的平方
//https://leetcode.cn/problems/squares-of-a-sorted-array/description/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int pre = 0;
        int end = nums.size() - 1;
        int new_vec_index = nums.size()-1;//从原数组的最大开始获取，题目要求非递减排序，所以索引从新数组末尾开始填充
        vector<int> new_vec(new_vec_index+1);//新数组存放处理过的数字

        while (pre <= end) {
            if (nums.at(pre)*nums.at(pre) > nums.at(end)*nums.at(end)) {
                new_vec.at(new_vec_index--) = nums.at(pre)*nums.at(pre);
                pre++;
            } else {
                new_vec.at(new_vec_index--) = nums.at(end)*nums.at(end);
                end--;
            }
        }
        return new_vec;
    }
    
    void demo() {
        Solution solution;
        vector<int> vec = {-5, 1, 2, 3, 10};
        vector<int> new_vec = solution.sortedSquares(vec);

        for (auto& num : new_vec) {
            cout << num << " ";
        }
    }
};


