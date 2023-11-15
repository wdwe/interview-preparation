#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <cctype>

class Solution {
public:
    static int calculate(std::string s) {
        int res = 0, sign = 1, num = 0;
        std::vector<std::pair<int, int>> stack;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (c == '-') {
                sign = -1;
            } else if (std::isdigit(c)) {
                while (std::isdigit(c)) {
                    num = num * 10 + (c - '0') * sign;
                    ++i;
                    c = s[i];
                }
                --i;
                res += num;
                num = 0;
            } else if (c == '+') {
                sign = 1;
            } else if (c == ' ') {
                continue;
            } else if (c == '(') {
                stack.emplace_back(res, sign);
                sign = 1;
                res = num = 0;
            } else if (c == ')') {
                int bracket_sign = stack.back().second;
                res = stack.back().first + res * bracket_sign;
                stack.pop_back();
            }
        }
        return res;
    }
//    static int calculate(std::string s) {
//        std::vector<std::string> st;
//        std::string item;
//        for (char c: s) {
//            if (c == '-' || c == '(' || c == ' ') {
//                if (!item.empty()) {
//                    st.push_back(item);
//                    item.clear();
//                }
//                if (c != ' ') st.push_back(std::string{c});
//            }
//            else if (c == '+') {
//                if (!item.empty()) {
//                    st.push_back(item);
//                    item.clear();
//                }
//                st.push_back(std::string{c});
//            }
//            else if (c == ')') {
//                if (!item.empty()) st.push_back(item);
//                int res = 0;
//                int op = std::stoi(st.back()); st.pop_back();
//                if (st.back() == "(") res += op;
//                while (st.back() != "(") {
//                    if (st.back() == "+") res += op;
//                    else if (st.back() == "-") res -= op;
//                    else {
//                        op = std::stoi(st.back());
//                        if (st[st.size() - 2] == "(") res += op;
//                    }
//                    st.pop_back();
//                }
//                st.pop_back();
//                st.push_back(std::to_string(res));
//            }
//            else item += c;
//        }
//        if (!item.empty()) st.push_back(item);
//        int res = 0, op = std::stoi(st.back());
//        st.pop_back();
//        if (st.empty()) res += op;
//        while (!st.empty()) {
//            if (st.back() == "+") res += op;
//            else if (st.back() == "-") res -= op;
//            else {
//                op = std::stoi(st.back());
//                if (st.size() == 1) res += op;
//            }
//            st.pop_back();
//        }
//        return res;
//    }
};


int main() {
    // "(1+(4+5+2)-3)+(6+8)"
    std::string s{"- (3 + (4 + 5))"};
    std::cout << Solution::calculate(s) << std::endl;
}
