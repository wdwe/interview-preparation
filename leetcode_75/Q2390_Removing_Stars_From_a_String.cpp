#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

class Solution {
public:
    std::string removeStars(std::string s) {
        std::vector<char> st;
        for (char c: s) {
            if (c == '*')
                st.pop_back();
            else
                st.push_back(c);
        }
        std::string res(st.begin(), st.end());
        // std::copy(st.begin(), st.end(), std::back_inserter(res));
        return res;
    }
};