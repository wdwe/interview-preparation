#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<int> prev(matrix[0].size(), 0), curr(matrix[0].size(), 0);
        for (const vector<int> &row: matrix) {
            for (std::size_t col = 0; col < row.size(); col++) {
                int val = prev[col];
                if (col > 0) val = std::min(val, prev[col - 1]);
                if (col < row.size() - 1) val = std::min(val, prev[col + 1]);
                curr[col] = val + row[col];
            }
            std::swap(curr, prev);
        }
        return *std::min_element(prev.cbegin(), prev.cend());
    }
};