#include <vector>
#include <algorithm>
//#include <tuple>
//#include <functional>

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;


class Solution {
public:
    static vvi merge(vvi& intervals) {
//        auto comp = [] (const vi& v1, const vi& v2) {
//            return std::tie(v1[0], v1[1]) < std::tie(v2[0], v2[1]);
//        };
        std::sort(intervals.begin(), intervals.end());
        int left, right;
        left = intervals[0][0];
        right = intervals[0][1];
        vvi res;
        for (int i = 1; i < intervals.size(); ++i) {
            int curr_l = intervals[i][0], curr_r = intervals[i][1];
            if (curr_l > right) {
                res.push_back({left, right});
                left = curr_l;
                right = curr_r;
            } else {
                right = std::max(curr_r, right);
            }
        }
        res.push_back({left, right});
        return res;
    }
};