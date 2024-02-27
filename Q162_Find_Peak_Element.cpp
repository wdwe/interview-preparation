#include <climits>
#include <vector>
using std::vector;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return binary_search(nums, 0, nums.size());
    }

    int binary_search(vector<int>& nums, int i, int j) {
        int mid = (i + j) / 2;
        bool left_smaller = (mid - 1 < 0) || (nums[mid - 1] < nums[mid]);
        bool right_smaller = (mid + 1 >= nums.size()) || (nums[mid + 1] < nums[mid]);
        if (left_smaller && right_smaller)
            return mid;
        if (left_smaller)
            return binary_search(nums, mid + 1, j);
        return binary_search(nums, i, mid);
    }
};