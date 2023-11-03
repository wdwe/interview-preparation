#include <vector>
#include <unordered_map>


class Solution {
public:
    static std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> res;
        std::unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); ++i) {
            if (seen.contains(target - nums[i])) {
                res.push_back(seen[target - nums[i]]);
                res.push_back(i);
                break;
            }
            seen[nums[i]] = i;
        }
        return res;
    }
};