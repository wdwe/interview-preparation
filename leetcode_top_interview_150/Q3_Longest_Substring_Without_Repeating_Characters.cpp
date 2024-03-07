#include <string>
#include <unordered_set>

class Solution {
public:
    static int lengthOfLongestSubstring(std::string s) {
        if (s.length() == 0) return 0;
        int i = 0, j = 1, res = 1;
        std::unordered_set<char> seen{s.at(0)};
        while (j < s.length()) {
            char c = s.at(j);
            if (!seen.contains(c)) {
                res = std::max(res, j - i + 1);
                seen.insert(c);
            } else {
                while (s.at(i) != c) seen.erase(s.at(i++));
                ++i;
            }
            ++j;
        }
        return res;
    }
};