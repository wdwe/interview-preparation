#include <vector>
#include <string>


class Solution {
public:
    static int evalRPN(std::vector<std::string>& tokens) {
        std::vector<int> stack;
        for (auto& s: tokens){
            if (s == "*" || s == "/" || s == "-" || s == "+") {
                int right = stack.back(); stack.pop_back();
                int left = stack.back(); stack.pop_back();
                int res;
                if (s == "*") res = left * right;
                else if (s == "/") res = left / right;
                else if (s == "-") res = left - right;
                else res = left + right;
                stack.push_back(res);
            }
            else {
                stack.push_back(std::stoi(s));
            }
        }
        return stack.back();
    }
};