#include <string>

using std::string;

class Solution {
public:
    string longestPalindrome(string s) {
        string even_palin = longest_even_palindrome(s);
        string odd_palin = longest_odd_palindrome(s);
        if (even_palin.size() > odd_palin.size())
            return even_palin;
        return odd_palin;
    }

    string longest_odd_palindrome(const string &s) {
        int max_pos = 0, max_len = 0;
        for (int pos = 0; pos < s.size(); ++pos) {
            int l = 0, left, right;
            while (true) {
                left = pos - l;
                right = pos + l;
                if (left < 0 || right >= s.size() || s[left] != s[right])
                    break;
                ++l;
            }
            --l;
            if (l > max_len) {
                max_pos = pos;
                max_len = l;
            }
        }
        return s.substr(max_pos - max_len, 2 * max_len + 1);
    }

    string longest_even_palindrome(const string &s) {
        int max_pos = 0, max_len = 0;
        for (int pos = 0; pos < s.size(); ++pos) {
            int l = 1, left, right;
            while (true) {
                left = pos - l + 1;
                right = pos + l;
                if (left < 0 || right >= s.size() || s[left] != s[right])
                    break;
                ++l;
            }
            --l;
            if (l > max_len) {
                max_pos = pos;
                max_len = l;
            }
        }

        return s.substr(max_pos - max_len + 1, 2 * max_len);

    }
};