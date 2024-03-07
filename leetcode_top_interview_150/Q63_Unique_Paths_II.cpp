#include <vector>

using std::vector;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<int> row(obstacleGrid[0].size(), 0);
        row[0] = 1 - obstacleGrid[0][0];
        for (int c = 1; c < row.size(); ++c) {
            if (!obstacleGrid[0][c])
                row[c] = row[c - 1];
            else
                break;

        }
        for (int r = 1; r < obstacleGrid.size(); ++r) {
            if (obstacleGrid[r][0])
                row[0] = 0;
            for (int c = 1; c < row.size(); ++c) {
                if (obstacleGrid[r][c])
                    row[c] = 0;
                else
                    row[c] += row[c - 1];
            }
        }
        return row[row.size() - 1];
    }
};