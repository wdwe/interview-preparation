#include <functional>
#include <unordered_map>
#include <vector>
#include <bit>
#include <climits>

template<class T>
struct VectorHash {
    std::size_t operator()(const std::vector<T>& vi) const {
        if (vi.empty())
            return 0;
        std::size_t h = std::hash<T>()(vi[0]);
        for (std::size_t i = 1; i < vi.size(); ++i) {
            h = h ^ std::rotr(std::hash<T>()(vi[i]), static_cast<int>(i % (sizeof(std::size_t) * 8)));
        }
        return h;
    }
};


class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        std::unordered_map<vector<int>, int, VectorHash<int>> r_map;
        for (auto &r: grid) {
            r_map[r]++;
        }

        int res = 0;
        for (std::size_t c = 0; c < grid[0].size(); ++c) {
            std::vector<int> col;
            for (std::size_t r = 0; r < grid.size(); ++r) {
                col.push_back(grid[r][c]);
            }
            if (r_map.contains(col))
                res += r_map[col];
        }

        return res;
    }
};