#include <string>
#include <stack>
#include <iostream>

class Solution {
public:
    static std::string simplifyPath(std::string path) {
//        std::stack<std::string> st;
        std::vector<std::string> st, stubs;
        std::size_t last = 0, next;
        while ((next = path.find('/', last)) != std::string::npos) {
            stubs.push_back(path.substr(last, next - last));
            last = next + 1;
        }
        stubs.push_back(path.substr(last));
        for (auto &p: stubs) {
            if (p.empty() || p == ".") continue;
            else if (p == "..") {
                if (!st.empty()) st.pop_back();
            }
            else st.push_back(p);
        }
        std::string abs_path = "/";
        for (auto it = st.begin(); it != st.end(); ++it) {
            if (it != st.begin()) abs_path += "/";
            abs_path += *it;
        }
        return abs_path;
    }
};

int main() {
    Solution::simplifyPath("/../");
}