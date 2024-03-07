#include <algorithm>
#include <sstream>
#include <unordered_set>

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
std::ostream& operator<<(std::ostream& stream, vvi m);

class Solution {
public:
    static void rotate(vvi& matrix) {
        int s = 0, e = matrix.size() - 1;
        rotate_layer(matrix, s, e);
    }

private:
    static void rotate_layer(vvi& matrix, int s, int e) {
        int N = e - s;
        if (N <= 0) return;
        for (int pos = 0; pos <= N - 1; ++pos) {
            int x = pos, y = 0;
            int orig_x = x + s, orig_y = 0 + s;
            int val = matrix.at(orig_y).at(orig_x);
            for (int side = 0; side < 4; ++side) {
                int next_x = N - y, next_y = x;
//                if (side & 1) {
//                    next_x = y;
//                    next_y = N - x;
//                }
                orig_x = x + s; orig_y = 0 + s;
                int orig_next_x = next_x + s, orig_next_y = next_y + s;
                int tmp = matrix.at(orig_next_y).at(orig_next_x);
//                std::cout << "orig_x: " << orig_x << " orig_y: " << orig_y << std::endl;
//                std::cout << "orig_next_x: " << orig_next_x << " orig_next_y: " << orig_next_y << std::endl;
//                std::cout << "val: " << val << std::endl;
                matrix.at(orig_next_y).at(orig_next_x) = val;
                val = tmp;
                x = next_x; y = next_y;
                // std::cout << matrix << std::endl;
            }
        }
        rotate_layer(matrix, s + 1, e - 1);
    }
};

std::ostream& operator<<(std::ostream& stream, vvi m) {
    stream << "[";
    for (auto row = m.cbegin(); row != m.cend(); ++row) {
        if (row != m.cbegin()) stream << "," << std::endl << " ";
        stream << "[";
        for (auto val = row->cbegin(); val != row->cend(); ++val) {
            if (val != row->cbegin()) stream << ", ";
            stream << *val;
        }
        stream << "]";
    }
    stream << "]";
    return stream;
}