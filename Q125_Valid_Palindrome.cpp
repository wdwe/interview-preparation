#include <string>
#include <cctype>


class Solution {
public:
    bool isPalindrome(std::string s) {
        int b = 0, e = (int) s.length() - 1;
        while (b <= e) {
            if (!std::isalnum(s.at(b))) {
                ++b;
                continue;
            }
            if (!std::isalnum(s.at(e))){
                --e;
                continue;
            }
            if (std::tolower(s.at(b)) != std::tolower(s.at(e)))
                return false;
            ++b;
            --e;
        }
        return true;
    }
};