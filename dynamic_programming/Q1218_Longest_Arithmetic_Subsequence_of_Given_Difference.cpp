#include <vector>
#include <algorithm>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
    int longestSubsequence(vector<int> &arr, int difference) {
        vector<int> dp(arr.size(), 1);
        unordered_map<int, int> seen;
        int res = 1;
        seen[arr[0]] = 1;
        for (int i = 1; i < arr.size(); ++i) {
            int num = arr[i] - difference;
            int count = 1;
            if (seen.contains(num)) {
                count = seen[num] + 1;
            }
            res = std::max(res, count);
            seen[arr[i]] = count;
        }
        return res;
    }
    // int longestSubsequence(vector<int>& arr, int difference) {
    //     vector<int> dp(arr.size(), 0);
    //     int res = 0;
    //     for (int i = 0; i < arr.size(); ++i) {
    //         res = std::max(res, longestSubsequenceRecur(arr, difference, i, arr.size(), dp));
    //     }
    //     return res;
    // }

    // int longestSubsequenceRecur(vector<int> &arr, int difference, int i, int n, vector<int> &dp) {
    //     int &num = dp[i];
    //     if (num) return num;
    //     num = 1;
    //     for (int j = i + 1; j < n; ++j) {
    //         if (arr[i] + difference == arr[j])
    //             num = std::max(num, longestSubsequenceRecur(arr, difference, j, n, dp) + 1);
    //     }
    //     return num;
    // }
};