#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c = 1;
        vector<int> res;
        for (auto it = digits.crbegin(); it != digits.crend(); it++) {
            int addition = c + *it;
            res.push_back(addition % 10);
            c = addition / 10;
        }
        if (c)
            res.push_back(c);
        std::reverse(res.begin(), res.end());
        return res;
    }
};