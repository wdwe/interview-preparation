#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    // int findLongestChain(vector<vector<int>>& pairs) {
    //     std::sort(pairs.begin(), pairs.end(), [](const vector<int> p1, const vector<int> p2) {
    //         if (p1[0] < p2[0]) return true;
    //         if (p1[0] == p2[0]) return p1[1] < p2[1];
    //         return false;
    //     });
    //     vector<int> dp(pairs.size(), 0);
    //     dp[0] = 1;
    //     for (std::size_t i = 1; i < dp.size(); ++i) {
    //         int len = 1;
    //         for (std::size_t j = 0; j < i; ++j) {
    //             int l = pairs[j][1], r = pairs[i][0];
    //             if (r > l) len = std::max(len, dp[j] + 1);
    //         }
    //         dp[i] = len;
    //     }
    //     return *std::max_element(dp.cbegin(), dp.cend());
    // }
    int findLongestChain(vector<vector<int>>& pairs) {
        std::sort(pairs.begin(), pairs.end());
        vector<int> memo(pairs.size());
        for (int i = 0; i < pairs.size(); ++i)
            findChainStartingFrom(i, pairs, memo, pairs.size());
        return *std::max_element(memo.cbegin(), memo.cend());
    }

    int findChainStartingFrom(int i, vector<vector<int>> &pairs, vector<int> &memo, int n) {
        int &count = memo[i];
        if (count > 0) return count;
        count = 1;
        for (int j = i + 1; j < n; ++j) {
            if (pairs[j][0] > pairs[i][1])
                count = std::max(count, findChainStartingFrom(j, pairs, memo, n) + 1);
        }
        return count;
    }
};