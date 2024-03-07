#include <vector>

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

class Solution {
public:
    static void setZeroes(vvi& matrix) {
        int H = matrix.size(), W = matrix.back().size();
        // check if first row needs to be set zero
        int first_row_zero = false;
        for (int x = 0; x < W; ++x)
            if (matrix.at(0).at(x) == 0) {
                first_row_zero = true;
                break;
            }

        // check if first col needs to be set zero
        int first_col_zero = false;
        for (int y = 0; y < H; ++y)
            if (matrix.at(y).at(0) == 0) {
                first_col_zero = true;
                break;
            }

        // use first row and column at the indicators
        for (int y = 1; y < H; ++y)
            for (int x = 1; x < W; ++x)
                if (matrix.at(y).at(x) == 0) {
                    matrix.at(0).at(x) = 0;
                    matrix.at(y).at(0) = 0;
                }

        // set the rest to zero if needed
        for (int y = 1; y < H; ++y)
            if (matrix.at(y).at(0) == 0)
                for (int x = 1; x < W; ++x)
                    matrix.at(y).at(x) = 0;

        for (int x = 1; x < W; ++x)
            if (matrix.at(0).at(x) == 0)
                for (int y = 1; y < H; ++y)
                    matrix.at(y).at(x) = 0;


        // set first col/row to zero if needed
        if (first_col_zero)
            for (int y = 0; y < H; ++y)
                matrix.at(y).at(0) = 0;

        if (first_row_zero)
            for (int x = 0; x < W; ++x)
                matrix.at(0).at(x) = 0;

    }
};