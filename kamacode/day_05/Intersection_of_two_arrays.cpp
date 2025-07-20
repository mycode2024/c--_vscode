//349. 两个数组的交集
//https://leetcode.cn/problems/intersection-of-two-arrays/

#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;

class Intersection_of_two_arrays {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result_set;
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for (int num : nums2) {
            if (nums_set.find(num) != nums_set.end()) {
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    } 
};