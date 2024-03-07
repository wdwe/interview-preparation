class Solution {
public:
    int findMin(vector<int>& nums) {
        // the key is that comparing with left bound does not give deterministic information
        // if mid is less than left bound, it may need to move left
        // if mid is more than left bound it may still need to move left
        // for comparing with the right bound
        // if mid is more than right, it needs to go right
        // if it is less, it needs to go left
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            int mid = i + (j - i) / 2;
            if (nums[mid] > nums[j])
                i = mid + 1;
            else
                j = mid;
        }
        return nums[i];
    }
};