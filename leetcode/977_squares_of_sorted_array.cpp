#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int pre = 0;
        int end = nums.size() - 1;
        int new_vec_index = nums.size()-1;
        vector<int> new_vec(new_vec_index+1);
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
};

void demo() {
    Solution solution;
    vector<int> vec = {-5, 1, 2, 3, 10};
    vector<int> new_vec = solution.sortedSquares(vec);

    for (auto& num : new_vec) {
        cout << num << " ";
    }
}

int main() {
    
    demo();
    return 0;
}