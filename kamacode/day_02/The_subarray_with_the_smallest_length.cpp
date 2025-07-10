//209. 长度最小的子数组
//https://leetcode.cn/problems/minimum-size-subarray-sum/description/

#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class The_subarray_with_the_smallest_length{
public:
    int minSubArrayLen_my(int target, vector<int>& nums) {
        int min_count = numeric_limits<int>::max();
        int temp_count = 0;
        int sum = 0;
        bool skip_flag = false;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                temp_count++;
                if (sum >= target) {
                    sum = 0;
                    if (min_count > temp_count) {
                        min_count = temp_count;
                    }
                    temp_count = 0;
                    skip_flag = true;
                    break;
                }
            }
            if (i == 0 && !skip_flag) {
                min_count = 0;
                break;
            }
            sum = 0;
            temp_count = 0;
        }
        return min_count;
    }

    int minSubArrayLen(int s, vector<int>& nums) {
        int result = INT_MAX;
        int sum = 0; // 滑动窗口数值之和
        int i = 0; // 滑动窗口起始位置
        int subLength = 0; // 滑动窗口的长度
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            // 注意这里使用while，每次更新 i（起始位置），并不断比较子序列是否符合条件
            while (sum >= s) {
                subLength = (j - i + 1); // 取子序列的长度
                result = result < subLength ? result : subLength;
                sum -= nums[i++]; // 这里体现出滑动窗口的精髓之处，不断变更i（子序列的起始位置）
            }
        }
        // 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
        return result == INT_MAX ? 0 : result;
    }
};

