//27. 移除元素
//https://leetcode.cn/problems/remove-element/description/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Remove_element{
public:
    int removeElement_my(vector<int>& nums, int val) {//27.移除元素，自己写的，时间复杂度O（n）
        if (nums.empty()) return 0; // 处理空数组
        
        auto begin_ = nums.begin();
        auto end_ = nums.end() - 1; // 指向最后一个元素
        
        while (begin_ <= end_) {
            if (*begin_ == val) {
                if (*end_ != val) {
                    swap(*begin_, *end_); // 交换元素
                    begin_++;
                    end_--;
                } else {
                    end_--; // 右指针左移
                }
            } else {
                begin_++; // 左指针右移
            }
        }
        return begin_ - nums.begin(); // 计算有效长度
    }

    int removeElement_my(vector<int>& nums,int val) {//27.移除元素
        int num = nums.size();
        int slowPoint = 0;
        for (int fastPoint = 0; fastPoint < num; fastPoint++) {
            if (nums[fastPoint] != val) {
                nums[slowPoint] = nums[fastPoint];
                slowPoint++;
            }
        }
        return slowPoint;
    }
};