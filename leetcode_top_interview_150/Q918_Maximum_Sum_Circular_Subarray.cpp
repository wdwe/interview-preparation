#include <vector>
#include <climits>
#include <algorithm>
using std::vector;

class Solution {
public:
// kadane max and kadane min
    int maxSubarraySumCircular(vector<int> &nums) {
        int max_sum = INT_MIN, max_curr = 0, min_sum = INT_MAX, min_curr = 0, total_sum = 0;
        for (int num: nums) {
            max_curr += num;
            min_curr += num;
            total_sum += num;
            max_sum = max_curr > max_sum? max_curr: max_sum;
            min_sum = min_curr < min_sum? min_curr: min_sum;
            if (max_curr < 0) max_curr = 0;
            if (min_curr > 0) min_curr = 0;
        }
        if (total_sum == min_sum)
            return max_sum;
        return std::max(max_sum, total_sum - min_sum);
    }
// suffix and prefix max sum
    // int maxSubarraySumCircular(vector<int>& nums) {
    //     // special max
    //     vector<int> suffix(nums.size(), 0);
    //     vector<int> prefix(nums.size(), 0);
    //     suffix[nums.size() - 1] = nums[nums.size() - 1];
    //     int sum = suffix[nums.size() - 1];
    //     for (int i = nums.size() - 2; i >= 0; --i) {
    //         sum += nums[i];
    //         suffix[i] = std::max(suffix[i + 1], sum);
    //     }
    //     prefix[0] = nums[0];
    //     sum = nums[0];
    //     for (int i = 1; i < nums.size(); ++i) {
    //         sum += nums[i];
    //         prefix[i] = std::max(prefix[i - 1], sum);
    //     }

    //     int special_max = INT_MIN;
    //     for (int i = 0; i < nums.size(); ++i) {
    //         int tmp = prefix[i];
    //         if (i + 1 < nums.size()) tmp += suffix[i + 1];
    //         special_max = std::max(special_max, tmp);
    //     }

    //     // normal max
    //     int normal_max = INT_MIN, curr = 0;
    //     for (int i = 0; i < nums.size(); ++i) {
    //         curr += nums[i];
    //         if (curr > normal_max) normal_max = curr;
    //         if (curr < 0) curr = 0;
    //     }

    //     return std::max(special_max, normal_max);
    // }

};