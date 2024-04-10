#include <unordered_map>
#include <algorithm>
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        // std::unordered_map<int, std::size_t> seen;
        // int count = 0;
        // for (int s: nums) {
        //     int d = k - s;
        //     if (seen.contains(d)) {
        //         seen[d]--;
        //         if (seen[d] == 0)
        //             seen.erase(d);
        //         count++;
        //     } else {
        //         seen[s]++;
        //     }
        // }
        // return count;
        std::sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1, count = 0;

        while (i < j) {
            int sum = nums[i] + nums[j];
            if (sum == k) {
                count++;
                j--;
                i++;
            } else if (sum > k) {
                j--;
            } else {
                i++;
            }
        }
        return count;
    }
};