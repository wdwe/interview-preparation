#include <vector>
using std::vector;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return binary_search(0, nums.size(), nums, target);
    }

    int binary_search(int i, int j, vector<int> &nums, int target) {
        if (i == j) return i;
        int mid = (i + j) / 2;
        if (nums[mid] == target) return mid;
        if (nums[mid] > target)
            return binary_search(i, mid, nums, target);
        return binary_search(mid + 1, j, nums, target);
    }
};