#include <vector>
#include <map>
#include <algorithm>

using std::vector;
using std::map;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        std::map<int, int> m;
        for (int i: nums) m[i] += i;
        int last = -1, take = 0, not_take = 0;
        for (auto [k, v]: m) {
            int old_not_take = not_take;
            not_take = max(old_not_take, take);
            if (last != k - 1)
                take = max(old_not_take, take) + v;
            else
                take = old_not_take + v;
            last = k;
        }
        return max(take, not_take);

    }
};