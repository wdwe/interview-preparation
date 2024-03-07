#include <map>
#include <vector>
#include <algorithm>

using std::map;
using std::vector;

class Solution {
public:
    // with the string building trick
    int lengthOfLIS(vector<int>& nums) {
        vector<int> seq;
        for (int n: nums) {
            auto it = std::lower_bound(seq.begin(), seq.end(), n);
            if (it == seq.end())
                seq.push_back(n);
            else if (*it != n)
                *it = n;
        }
        return seq.size();
    }


    // int lengthOfLIS(vector<int>& nums) {
    //     map<int, int> past;
    //     int max_seq = 0;
    //     for (int n: nums) {
    //         int len = 1;
    //         for (auto [k, v]: past) {
    //             if (k < n && v + 1> len)
    //                 len = v + 1;
    //             else if (k >= n)
    //                 break;
    //         }
    //         past[n] = len;
    //         if (len > max_seq)
    //             max_seq = len;
    //     }
    //     return max_seq;
    // }
};