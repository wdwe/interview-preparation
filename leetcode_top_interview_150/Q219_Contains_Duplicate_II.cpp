#include <vector>
#include <unordered_map>
#include <cmath>

class Solution {
public:
    static bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> pos;
        for (int i = 0; i < nums.size(); ++i) {
            if (pos.contains(nums[i]) && std::abs(pos[nums[i]]- i)<= k)
                return true;
            pos[nums[i]] = i;
        }
        return false;
    }
};