#include <string>
#include <cctype>
#include <vector>
#include <utility>

class Solution {
public:
    std::string decodeString(std::string s) {
        std::string res;
        std::vector<std::pair<std::size_t, int>> st;
        int rep = 0;
        for (char c: s) {
            if (std::isdigit(c)) {
                rep = rep * 10 + (c - '0');
            } else if (std::isalpha(c)) {
                res.push_back(c);
            } else if (c == '[') {
                st.emplace_back(res.size(), rep);
                rep = 0;
            } else { // c == ']'
                auto [pos, rep] = st.back();
                st.pop_back();
                std::string pat = res.substr(pos, res.size() - pos);
                for (int i = 0; i < rep - 1; ++i) {
                    res.append(pat);
                }
            }
        }
        return res;
    }
};