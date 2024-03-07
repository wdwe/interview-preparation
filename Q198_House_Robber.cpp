#include <vector>

using std::vector;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        int robbed = nums[0], not_robbed = 0;
        int res;
        for (std::size_t i = 1; i < nums.size(); ++i) {
            int tmp = not_robbed;
            not_robbed = robbed > tmp? robbed: tmp;
            robbed = tmp + nums[i];
            res = robbed > not_robbed? robbed: not_robbed;
        }
        return res;
    }
};