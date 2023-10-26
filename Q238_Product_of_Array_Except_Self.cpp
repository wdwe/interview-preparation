#include <vector>

using namespace std;


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // vector<int> prefix_product(nums);
        // vector<int> suffix_product(nums);
        // for (auto iter = prefix_product.begin() + 1; iter != prefix_product.end(); ++iter) {
        //     *iter *= *(iter - 1);
        // }
        // for (auto iter = suffix_product.rbegin() + 1; iter != suffix_product.rend(); ++iter) {
        //     *iter *= *(iter - 1);
        // }
        // vector<int> results;
        // for (size_t i = 0; i != nums.size(); ++i) {
        //     int prefix = (i > 0 ? prefix_product[i - 1] : 1);
        //     int suffix = (i < nums.size() - 1 ? suffix_product[i + 1] : 1);
        //     results.push_back(prefix * suffix);
        // }

        // return results;
        vector<int> results(nums.size(), 1);
        for (size_t i = 1; i < nums.size(); ++i) {
            results[i] = results[i - 1] * nums[i - 1];
        }
        int suffix = 1;
        for (int i = nums.size() - 2; i >= 0; --i) {
            suffix *= nums[i + 1];
            results[i] *= suffix;
        }
        return results;
    }
};