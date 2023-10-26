#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        std::vector<int> lps = build_lps(needle);
        int i = 0, j = 0;
        while (i < haystack.length()) {
            char c_s = haystack.at(i), c_p = needle.at(j);
            if (haystack.at(i) == needle.at(j)) {
                ++j;
                ++i;
                if (j == needle.length()) return i - j;
            } else {
                if (j == 0) ++i;
                else j = lps.at(j - 1);
            }
        }

        return -1;
    }
private:
    static std::vector<int> build_lps(std::string pat);
};

std::vector<int> Solution::build_lps(std::string pat) {
    int i = 1, j = 0;
    std::vector<int> lps = {0};
    while (i < pat.length()) {
        if (pat.at(i) == pat.at(j)) {
            ++j;
            lps.push_back(j);
            ++i;
        } else {
            if (j == 0) {
                lps.push_back(j);
                ++i;
            }
            else j = lps.at(j - 1);
        }
    }
    return lps;
}