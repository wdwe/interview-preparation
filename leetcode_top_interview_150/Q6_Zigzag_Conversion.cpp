#include <string>
#include <utility>
#include <algorithm>
#include <sstream>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows == 1) return s;
        int stride = 2 * numRows - 2;
        std::ostringstream output;
        for (int i = 0; i < s.size(); i += stride) {
            output << s.at(i);
        }
        for (int row = 1; row < numRows; ++row) {
            for (int i = 0; i < s.size(); i += stride){
                int first = row, second = stride - row;
                if (i + first < s.size())
                    output << s.at(i + first);
                if (second != first && i + second < s.size())
                    output << s.at(i + second);
            }
        }
        return output.str();

    }
};