#include <iostream>
#include <vector>
#include  <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(), false); 
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, 0, 0, target, used);
        return result;
    }

    void backtracking(vector<int>& candidates, int sum, int startIndex, int target, vector<bool>& used) {
        if (sum == target) {
            result.push_back(path);
            return ;
        }
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) {
                continue;
            }
            path.push_back(candidates[i]);
            sum += candidates[i];
            used[i] = true;
            backtracking(candidates, sum, i + 1, target, used);
            path.pop_back();
            sum -= candidates[i];
            used[i] = false;
        }
    }

private:
    vector<int> path;
    vector<vector<int>> result;
};