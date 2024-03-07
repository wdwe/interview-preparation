#include <string>
#include <unordered_map>

class Solution {
public:
    static std::string minWindow(std::string s, std::string t) {
        int l, r, prog;
        std::unordered_map<char, int> required, curr;
        for (char ch: t) ++required[ch];
        l = r = prog = 0;
        int res_l = -1, res_n = INT_MAX;
        while (r < s.length()) {
            char c = s[r];
            ++curr[c];
            if (required.contains(c) && curr.at(c) <= required.at(c)) ++prog;
            if (prog == t.length()) {
                char old_c = s.at(l);
                while (!required.contains(old_c) || curr.at(old_c) > required.at(old_c)) {
                    --curr[old_c];
                    old_c = s.at(++l);
                }
                int n = r - l + 1;
                if (n < res_n) {
                    res_n = n;
                    res_l = l;
                }
                // remove the needed char to find the next substring that satisfy the condition
                --prog;
                --curr[old_c];
                l++;
            }
            ++r;
        }
        if (res_l >= 0) return s.substr(res_l, res_n);
        return "";
    }
};