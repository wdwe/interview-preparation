#include <vector>
#include <algorithm>
//#include <iterator>


typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

class Solution {
    /*
     * learning point is whether to sort the balloons based on right end point or left end point
     */
public:
    static int findMinArrowShots(vvi& points) {
        vvi balloons = points;
//        std::copy(points.cbegin(), points.cend(), std::back_inserter(balloons));
        // balloons.assign(points.cbegin(), points.cend());
        std::sort(balloons.begin(), balloons.end(), [](const vi& l, const vi& r) {return l[1] < r[1];});
        int arrows = 1;
        int right = balloons[0][1];
        for (int i = 1; i < balloons.size(); ++i) {
            int left = balloons[i][0];
            if (left > right) {
                ++arrows;
                right = balloons[i][1];
            }
        }
        return arrows;
    }
};