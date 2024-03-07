#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for (int r = 1; r < word1.size() + 1; ++r)
            dp[r][0] = r;
        for (int c = 1; c < word2.size() + 1; ++c)
            dp[0][c] = c;

        for (int r = 1; r < word1.size() + 1; ++r) {
            for (int c = 1; c < word2.size() + 1; ++c) {
                // delete word1
                int cost_1 = dp[r - 1][c] + 1;
                // delete word 2
                int cost_2 = dp[r][c - 1] + 1;
                // replace or not
                int cost_r = dp[r - 1][c - 1];
                if (word1[r - 1] != word2[c - 1])
                    cost_r += 1;

                dp[r][c] = std::min({cost_1, cost_2, cost_r});
            }
        }

        return dp[word1.size()][word2.size()];

    }
};