#include <vector>
using std::vector;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = left_bound(nums, 0, nums.size(), target);
        int right = right_bound(nums, 0, nums.size(), target);
        return {left, right};
    }

    int binary_search(vector<int> &nums, int i, int j, int target) {
        if (i == j) return -1;
        int mid = i + (j - i) / 2;
        if (nums[mid] == target) return mid;
        if (nums[mid] < target) return binary_search(nums, mid + 1, j, target);
        return binary_search(nums, i, mid, target);
    }

    int left_bound(vector<int> &nums, int i, int j, int target) {
        int loc = binary_search(nums, i, j, target);
        if (loc == -1) return -1;
        int bound = left_bound(nums, i, loc, target);
        if (bound == -1) return loc;
        return bound;
    }

    int right_bound(vector<int> &nums, int i, int j, int target) {
        int loc = binary_search(nums, i, j, target);
        if (loc == -1) return -1;
        int bound = right_bound(nums, loc + 1, j, target);
        if (bound == -1) return loc;
        return bound;
    }
};