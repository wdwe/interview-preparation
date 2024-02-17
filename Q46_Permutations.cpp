#include <vector>
using std::vector;

class Solution {
// use swap
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        int idx = 0;
        permutate(nums, results, idx);
        return results;
    }

    void permutate(vector<int>& nums, vector<vector<int>>& results, int idx) {
        if (idx == results.size()) {
            results.emplace_back(nums);
            return;
        }

        for (int i = idx; i < nums.size(); ++i) {
            std::swap(nums[idx], nums[i]);
            permutate(nums, results, idx + 1);
            std::swap(nums[idx], nums[i]);
        }
    }
// use flags
//public:
//    vector<vector<int>> permute(vector<int>& nums) {
//        vector<vector<int>> results;
//        vector<bool> used(nums.size());
//        vector<int> prefix;
//        next(used, nums, prefix, results);
//        return results;
//    }
//
//    void next(vector<bool>& used, vector<int>& nums, vector<int>& prefix, vector<vector<int>>& results) {
//        if (prefix.size() == nums.size()) {
//            results.emplace_back(prefix);
//        } else {
//            for (int i = 0; i < nums.size(); ++i) {
//                if (!used[i]) {
//                    prefix.push_back(nums[i]);
//                    used[i] = true;
//                    next(used, nums, prefix, results);
//                    used[i] = false;
//                    prefix.pop_back();
//                }
//            }
//        }
//    }
};