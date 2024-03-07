#include <string>

using namespace std;


class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        if (s.length() == 0) return true;
        while (i < t.length()) {
            if (s.at(j) == t.at(i))
                if (++j == s.length())
                    return true;
            ++i;
        }
        return false;
    }
};