#include <string>
#include <algorithm>


using std::string;

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1;
        std::string res;
        int c = 0;
        while (i >= 0 || j >= 0) {
            int b1 = 0, b2 = 0;
            if (i >= 0){
                b1 = a[i] - '0';
                --i;
            }
            if (j >= 0) {
                b2 = b[j] - '0';
                --j;
            }
            int ans = c + b1 + b2;
            if (ans > 1) {
                c = 1;
                ans -= 2;
            } else {
                c = 0;
            }
            res.push_back('0' + ans);
        }
        if (c > 0) {
            res.push_back('1');
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};