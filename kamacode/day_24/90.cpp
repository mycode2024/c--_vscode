#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<bool> used(nums.size(),false);
        sort(nums.begin(), nums.end());
        backtracking(nums, 0, used);
        return result;
    }

    void backtracking(vector<int>& vec, int startIndex, vector<bool>& used) {
        result.push_back(path);
        for (int i = startIndex; i < vec.size(); i++) {
            if (i > 0 && vec[i] == vec[i - 1] && used[i - 1] == false) {
                continue;
            }
            path.push_back(vec[i]);
            used[i] = true;
            backtracking(vec, i + 1, used);
            path.pop_back();
            used[i] = false;
        }
    }
private:
    vector<vector<int>> result;
    vector<int> path;
};

int main() {
    Solution s;
    vector<int> vec{1, 2, 2};
    s.subsetsWithDup(vec);
    return 0;
}