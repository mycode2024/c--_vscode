#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(1, 0, k, n);
        return result;
    }

    void backtracking(int startIndex, int sum, int k, int n){
        if (sum > n) {
            return;
        }
        if (k == path.size()) {
            if (sum == n) {
                result.push_back(path);
            }
            return;
        }
        for (int i = startIndex; i <= 9 - (k - path.size()) + 1; i++) {
            path.push_back(i);
            sum += i;
            backtracking(i + 1, sum, k, n);
            path.pop_back();
            sum -= i;
        }
    }
private:
    vector<int> path;
    vector<vector<int>> result;
};