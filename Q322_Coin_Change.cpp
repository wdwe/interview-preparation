#include <vector>
#include <limits>

using std::vector;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // going bottom up
        vector<int> nums(amount + 1, -1);
        nums[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int c: coins) {
                if (i >= c && nums[i - c] >= 0) {
                    if (nums[i] == -1)
                        nums[i] = nums[i - c] + 1;
                    else
                        nums[i] = nums[i] < (nums[i - c] + 1)? nums[i]: (nums[i - c] + 1);
                }
            }
        }
        return nums[amount];
    }
};