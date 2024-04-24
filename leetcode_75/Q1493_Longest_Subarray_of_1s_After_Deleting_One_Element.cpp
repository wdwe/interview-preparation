#include <vector>
#include <algorithm>


class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        std::size_t i = 0, j = 1;
        int res = 0;
        bool del_one = nums[i] == 1;
        while (j < nums.size()) {
            if (nums[j] == 0) {
                if (del_one) {
                    del_one = false;
                } else { // move i
                    while (nums[i++] != 0)
                        ; // no need to check i < j as nums[j] is 0 anyway
                    del_one = false;
                }
            }
            j++;
            res = std::max(static_cast<int>(j - i - 1), res);
        }
        return res;
    }
};