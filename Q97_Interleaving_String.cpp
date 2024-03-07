#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.size() != s1.size() + s2.size())
            return false;
        vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));
        // initialise the first row and column
        // +---> s2
        // |
        // v
        // s1
        dp[0][0] = true;
        for (int r = 1; r < s1.size() + 1; ++r)
            dp[r][0] = (s1[r - 1] == s3[r - 1]) && dp[r - 1][0];
        for (int c = 1; c < s2.size() + 1; ++c)
            dp[0][c] = (s2[c - 1] == s3[c - 1]) && dp[0][c - 1];

        for (int r = 1; r < s1.size() + 1; ++r) {
            for (int c = 1; c < s2.size() + 1; ++c) {
                dp[r][c] = (dp[r - 1][c] && (s1[r - 1] == s3[r + c - 1])) || (dp[r][c - 1] && (s2[c - 1] == s3[r + c - 1]));
            }
        }
        return dp[s1.size()][s2.size()];

    }
};