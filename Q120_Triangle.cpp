#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int>());
        for (int i = 0; i < triangle.size(); ++i) {
            dp[i].assign(i + 1, 0);
        }
        dp[0][0] = triangle[0][0];
        for (int l = 1; l < triangle.size(); ++l) {
            for (int i = 0; i < l + 1; ++i) {
                if (i - 1 >= 0 && i < l)
                    dp[l][i] = std::min(dp[l - 1][i - 1], dp[l - 1][i]) + triangle[l][i];
                else if (i - 1 >= 0)
                    dp[l][i] = dp[l - 1][i - 1] + triangle[l][i];
                else
                    dp[l][i] = dp[l - 1][i] + triangle[l][i];
            }
        }
        const auto &bottom = dp[dp.size() - 1];
        return *std::min_element(bottom.cbegin(), bottom.cend());
    }
};