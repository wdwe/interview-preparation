#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> results;
        vector<int> prefix;
        for (int i = 1; i <= n; ++i) {
            backtrack(results, i, prefix, n, k);
        }
        return results;
    }

    void backtrack(vector<vector<int>> &results, int idx, vector<int> &prefix, int n, int k) {
        prefix.push_back(idx);
        if (prefix.size() == k) {
            results.emplace_back(prefix);
        } else {
            for (int i = idx + 1; i <= n; i++)
                backtrack(results, i, prefix, n, k);
        }
        prefix.pop_back();
    }
};