#include <vector>
using std::vector;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int k = binary_search_k(nums, 0, nums.size() - 1);
        return binary_search(nums, 0, nums.size(), target, k);
    }

    int binary_search_k(vector<int> &nums, int i, int j) {
        if (i == j) return i;
        int mid = (i + j) / 2;
        if (nums[mid] > nums[j])
            return binary_search_k(nums, mid + 1, j);
        else
            return binary_search_k(nums, i, mid);
    }

    int binary_search(vector<int> &nums, int i, int j, int target, int k) {
        if (i == j) return -1;
        int mid = (i + j) / 2;
        int mid_idx = (mid + k) % nums.size();
        if (target == nums[mid_idx]) return mid_idx;
        if (target < nums[mid_idx])
            return binary_search(nums, i, mid, target, k);
        return binary_search(nums, mid + 1, j, target, k);
    }
};