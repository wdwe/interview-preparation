#include <string>
#include <utility>
#include <algorithm>
#include <sstream>

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        int length = 0;
        for (auto iter = s.crbegin(); iter != s.crend(); ++iter) {
            if (*iter == ' ') {
                if (length == 0) continue;
                break;
            }
            ++length;
        }
        return length;
    }
};