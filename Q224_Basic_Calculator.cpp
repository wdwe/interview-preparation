#include <string>
#include <vector>
#include <iostream>

class Solution {
public:
    static int calculate(std::string s) {
        std::vector<std::string> st;
        std::string item;
        for (char c: s) {
            if (c == '-' || c == '(' || c == ' ') {
                if (!item.empty()) {
                    st.push_back(item);
                    item.clear();
                }
                if (c != ' ') st.push_back(std::string{c});
            }
            else if (c == '+') {
                if (!item.empty()) {
                    st.push_back(item);
                    item.clear();
                }
                st.push_back(std::string{c});
            }
            else if (c == ')') {
                if (!item.empty()) st.push_back(item);
                int res = 0;
                int op = std::stoi(st.back()); st.pop_back();
                if (st.back() == "(") res += op;
                while (st.back() != "(") {
                    if (st.back() == "+") res += op;
                    else if (st.back() == "-") res -= op;
                    else {
                        op = std::stoi(st.back());
                        if (st[st.size() - 2] == "(") res += op;
                    }
                    st.pop_back();
                }
                st.pop_back();
                st.push_back(std::to_string(res));
            }
            else item += c;
        }
        if (!item.empty()) st.push_back(item);
        int res = 0, op = std::stoi(st.back());
        st.pop_back();
        if (st.empty()) res += op;
        while (!st.empty()) {
            if (st.back() == "+") res += op;
            else if (st.back() == "-") res -= op;
            else {
                op = std::stoi(st.back());
                if (st.size() == 1) res += op;
            }
            st.pop_back();
        }
        return res;
    }
};


int main() {
    std::string s{"(1+(4+5+2)-3)+(6+8)"};
    std::cout << Solution::calculate(s) << std::endl;
}
