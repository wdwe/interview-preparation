#include <unordered_map>
#include <vector>
#include <algorithm>

using std::vector;
using std::unordered_map;

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        vector<unordered_map<int, int>> dp(nums.size());
        int res = 1;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                int diff = nums[i] - nums[j];
                dp[i][diff] = dp[j].contains(diff)? std::max(dp[i][diff], dp[j][diff] + 1): std::max(dp[i][diff], 2);
                res = std::max(res, dp[i][diff]);
            }
        }
        return res;
    }
};