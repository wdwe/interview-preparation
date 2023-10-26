#include <vector>


typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

class Solution {
public:
    static std::vector<int> spiralOrder(vvi& matrix) {
        vi output;
        int x1 = 0, y1 = 0, x2 = matrix.front().size(), y2 = matrix.size();
        spiral(matrix, output, x1, y1, x2, y2);
        return output;
    }

private:
    static void spiral(vvi& matrix, vi& output, int x1, int y1, int x2, int y2) {
        if (x1 >= x2 || y1 >= y2) return;
        if (x1 == x2 - 1) { // single column
            for (int y = y1; y < y2; ++y) output.push_back(matrix.at(y).at(x1));
            return;
        }
        if (y1 == y2 - 1) { // single row
            for (int x = x1; x < x2; ++x) output.push_back(matrix.at(y1).at(x));
            return;
        }

        // take the boundary cells of the given matrix boundary
        for (int x = x1; x < x2 - 1; ++x) output.push_back(matrix.at(y1).at(x));
        for (int y = y1; y < y2 - 1; ++y) output.push_back(matrix.at(y).at(x2 - 1));
        for (int x = x2 - 1; x > x1; --x) output.push_back(matrix.at(y2 - 1).at(x));
        for (int y = y2 - 1; y > y1; --y) output.push_back(matrix.at(y).at(x1));

        // take the inner boudary's cells
        spiral(matrix, output, x1 + 1, y1 + 1, x2 - 1, y2 - 1);
    }
};