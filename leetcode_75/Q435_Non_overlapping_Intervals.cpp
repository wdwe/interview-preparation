#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int count = 0;
        int end = intervals[0][1];
        for (size_t i = 1; i < intervals.size(); ++i) {
            int s = intervals[i][0];
            int e = intervals[i][1];
            if (s < end) {
                count++;
                end = min(e, end);
            } else {
                end = e;
            }
        }
        return count;
    }
};