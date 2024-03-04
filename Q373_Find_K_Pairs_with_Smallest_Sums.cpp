#include <vector>
#include <unordered_set>
#include <queue>
#include <tuple>
#include <utility>
#include <algorithm>
#include <functional>
#include <bit>
using std::vector;
using std::priority_queue;
using std::pair;
using std::tuple;
using std::unordered_set;

typedef tuple<int, int, int> item_t;

template<class T1, class T2> struct std::hash<pair<T1, T2>> {
public:
std::size_t operator()(pair<T1, T2> p) const {
    std::size_t h1 = std::hash<T1>{}(p.first);
    std::size_t h2 = std::hash<T2>{}(p.second);
    return std::rotl(h1, 1) ^ h2;
}
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<item_t, vector<item_t>, std::greater<>> pq;
        pq.emplace(nums1[0] + nums2[0], 0, 0);
        unordered_set<pair<int, int>> seen;
        vector<vector<int>> res;
        while (!pq.empty() && k > 0) {
            auto [sum, i, j] = pq.top();
            pq.pop();
            if (!seen.contains({i, j})) {
                res.push_back({nums1[i], nums2[j]});
                --k;
                seen.emplace(i, j);
                if (i + 1 < nums1.size())
                    pq.emplace(nums1[i + 1] + nums2[j], i + 1, j);
                if (j + 1 < nums2.size())
                    pq.emplace(nums1[i] + nums2[j + 1] , i, j + 1);
            }
        }

        return res;
    }
};