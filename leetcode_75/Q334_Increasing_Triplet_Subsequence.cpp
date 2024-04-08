#include <vector>
#include <algorithm>

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // if (nums.size() < 3) return false;
        // std::vector<int> larger(nums.size(), 0);
        // larger[nums.size() - 1] = nums[nums.size() - 1];
        // for (int i = nums.size() - 2; i >= 0; --i) {
        //     larger[i] = std::max(nums[i], larger[i + 1]);
        // }
        // int smaller = nums[0];
        // for (int i = 1; i < nums.size(); ++i) {
        //     if (larger[i] > nums[i] && nums[i] > smaller)
        //         return true;
        //     smaller = std::min(smaller, nums[i]);
        // }
        // return false;
        bool second_found = false;
        int first, second;
        first = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (second_found && nums[i] > second)
                return true;
            if (nums[i] <= first)
                first = nums[i];
            else if (!second_found || nums[i] <= second){
                second = nums[i];
                second_found = true;
            }
        }
        return false;
    }
};