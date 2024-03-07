#include <vector>

using namespace std;


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        vector<int> sums = {};
        sums.push_back(nums.at(0));
        for (int i = 1; i < nums.size(); ++i) {
            sums.push_back(sums.at(i - 1) + nums.at(i));
        }
        int i = -1, j = 0, res = nums.size() + 1;
        while (j < nums.size()) {
            int curr = sums.at(j) - (i >= 0 ? sums.at(i): 0);
            if (curr >= target) {
                res = min(res, j - i);
                if (i < j) ++i;
                else ++j;
            } else ++j;
        }
        res = res <= nums.size() ? res : 0;
        return res;
    }
};