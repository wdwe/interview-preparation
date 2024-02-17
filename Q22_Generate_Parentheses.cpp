#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        vector<char> prefix;
        backtrack(n, n, res, prefix);
        return res;
    }

    void backtrack(int f_n, int b_n, vector<string>& res, vector<char>& prefix) {
        if (f_n == 0 && b_n == 0){
            string s;
            for (char c: prefix) {
                s.push_back(c);
            }
            res.emplace_back(s);
            return;
        }
        if (f_n > 0) {
            prefix.push_back('(');
            backtrack(f_n - 1, b_n, res, prefix);
            prefix.pop_back();
        }
        if (f_n < b_n) {
            prefix.push_back(')');
            backtrack(f_n, b_n - 1, res, prefix);
            prefix.pop_back();
        }
    }
};