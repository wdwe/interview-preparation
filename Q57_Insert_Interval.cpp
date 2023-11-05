#include <vector>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

class Solution {
public:
    static vvi insert(vvi& intervals, vi& newInterval) {
        int left = newInterval[0], right = newInterval[1];
        int i = 0;
        vvi res;
        while (i < intervals.size()) {
            int curr_r = intervals[i][1];
            if (left <= curr_r) break;
            res.push_back(intervals[i]);
            ++i;
        }
        while (i < intervals.size()) {
            if (right < intervals[i][0]) {
                res.push_back({left, right});
                break;
            }
            left = std::min(intervals[i][0], left);
            right = std::max(intervals[i][1], right);
            ++i;
        }
        if (i == intervals.size()) res.push_back({left, right});
        else res.insert(res.end(), intervals.begin()+i, intervals.end());
        return res;
    }
};