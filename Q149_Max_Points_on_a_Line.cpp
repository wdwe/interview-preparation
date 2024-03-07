#include <functional>
#include <utility>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <limits>

using std::unordered_map;
using std::pair;
using std::vector;
using std::unordered_set;

typedef pair<int, int> p_ii;
typedef pair<p_ii, p_ii> segment;
typedef pair<double, double> p_dd;


struct PairHash {
    template<class T1, class T2>
    std::size_t operator()(const pair<T1, T2> &p) const{
        return std::rotl(std::hash<T1>{}(p.first), 1) ^ std::hash<T2>{}(p.second);
    }
};



class Solution {
public:
    // a more efficient solution will be fix one point at a time and compute the gradient
    // of the segment formed by other points with this point
    // then, no y-intercept is needed
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() == 1)
            return 1;
        unordered_map<p_dd, vector<segment>, PairHash> collinear_segs;
        for (int i = 0; i < points.size(); ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                p_dd li = gradient_intercept({x1, y1}, {x2, y2});
                collinear_segs[li].push_back({{x1, y1}, {x2, y2}});
            }
        }

        unordered_map<p_dd, unordered_set<p_ii, PairHash>, PairHash> collinear_pts;

        std::size_t sz = 0;
        for (auto &[li, segs]: collinear_segs) {
            for (segment &s: segs) {
                collinear_pts[li].insert(s.first);
                collinear_pts[li].insert(s.second);
            }
            if (collinear_pts[li].size() > sz)
                sz = collinear_pts[li].size();
        }
        return sz;
    }

    p_dd gradient_intercept(p_ii p1, p_ii p2) {
        double x1 = p1.first;
        double y1 = p1.second;
        double x2 = p2.first;
        double y2 = p2.second;
        if (x1 == x2)
            return {std::numeric_limits<double>::infinity(), x1};
        if (y1 == y2)
            return {0, y1};
        double gradient = (y2 - y1) / (x2 - x1);
        double intercept = y2 - gradient * x2;
        return {gradient, intercept};
    }

};