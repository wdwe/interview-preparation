#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<int> prev_row(grid[0].size(), 0);
        vector<int> row(grid[0].size(), 0);
        prev_row[0] = grid[0][0];
        for (int c = 1; c < grid[0].size(); ++c) {
            prev_row[c] = prev_row[c - 1] + grid[0][c];
        }

        for (int r = 1; r < grid.size(); ++r) {
            row[0] = prev_row[0] + grid[r][0];
            for (int c = 1; c < grid[r].size(); ++c) {
                row[c] = std::min(row[c - 1], prev_row[c]) + grid[r][c];
            }
            std::swap(prev_row, row);
        }

        return prev_row[prev_row.size() - 1];
    }
};