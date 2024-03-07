#include <string>
#include <utility>
#include <algorithm>
#include <sstream>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.size() == 0) return "";

        std::stringstream prefix;
        int i = 0;
        while (true) {
            std::string s = strs.at(0);
            if (i != s.length()) {
                char c = s.at(i);
                for (int j = 1; j < strs.size(); ++j) {
                    std::string ss = strs.at(j);
                    if (i == ss.length() || ss.at(i) != c) return prefix.str();
                }
            } else
                return prefix.str();
            prefix << strs.at(0).at(i);
            ++i;
        }
    }
};