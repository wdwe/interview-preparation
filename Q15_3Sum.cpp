#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int k = 0;
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        while (k < nums.size() - 2) {
            int i = k + 1, j = nums.size() - 1;
            int t = 0 - nums.at(k);
            while (i < j) {
                if (nums.at(i) + nums.at(j) == t) {
                    res.push_back(vector<int>{nums.at(k), nums.at(i), nums.at(j)});
                    ++i;
                    while (i < j && nums.at(i) == nums.at(i - 1)) ++i;
                }
                else if (nums.at(i) + nums.at(j) < t) {
                    ++i;
                    while (i < j && nums.at(i) == nums.at(i - 1)) ++i;
                } else {
                    --j;
                    while (i < j && nums.at(j) == nums.at(j + 1)) --j;
                }
            }
            ++k;
            while (k < nums.size() - 2 && nums.at(k) == nums.at(k - 1)) ++k;
        }
        return res;
    }
};