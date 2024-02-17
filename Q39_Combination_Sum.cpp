#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        vector<int> partial;
        backtrack(results, target, candidates, 0, partial);
        return results;
    }

    void backtrack(vector<vector<int>>& results, int target, vector<int>& candidates, int idx, vector<int>& partial) {
        if (target == 0) {
            results.emplace_back(partial);
            return;
        }
        if (target < 0)
            return;

        for (int i = idx; i < candidates.size(); ++i) {
            partial.push_back(candidates[i]);
            backtrack(results, target - candidates[i], candidates, i, partial);
            partial.pop_back();
        }
    }
};