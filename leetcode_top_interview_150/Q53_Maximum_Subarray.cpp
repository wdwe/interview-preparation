#include <vector>
#include <climits>
using std::vector;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = 0, max_sum = INT_MIN;
        for (int num: nums) {
            curr += num;
            if (curr > max_sum) max_sum = curr;
            if (curr < 0) curr = 0;
        }
        return max_sum;
    }
/* two pointers with sum array*/
    // int maxSubArray(vector<int>& nums) {
    //     vector<int> sums;
    //     if (!nums.empty()) sums.push_back(nums[0]);
    //     for (int i = 1; i < nums.size(); ++i) {
    //         sums.push_back(nums[i] + sums[i - 1]);
    //     }
    //     int i = 0, j = 0;
    //     int max = INT_MIN;
    //     while (j < nums.size()) {
    //         int subsum = sums[j] - sums[i] + nums[i];
    //         max = subsum > max? subsum: max;
    //         ++j;
    //         if (subsum <= 0)
    //             i = j;
    //     }
    //     return max;
    // }
};