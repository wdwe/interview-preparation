#include <vector>
#include <algorithm>

using std::vector;


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<int> side(matrix[0].size(), 0);
        int max_side = 0;
        for (int i = 0; i < matrix[0].size(); ++i) {
            side[i] = matrix[0][i] - '0';
            max_side = std::max(side[i], max_side);
        }

        for (int r = 1; r < matrix.size(); ++r) {
            int diag_side = side[0];
            side[0] = matrix[r][0] - '0';
            max_side = std::max(max_side, side[0]);
            for (int c = 1; c < matrix[0].size(); ++c) {
                if (matrix[r][c] == '0') {
                    diag_side = side[c];
                    side[c] = 0;
                } else {
                    int tmp = side[c];
                    side[c] = std::min({side[c], side[c - 1], diag_side}) + 1;
                    diag_side = tmp;
                    max_side = std::max(max_side, side[c]);
                }
            }
        }
        return max_side * max_side;

    }
};