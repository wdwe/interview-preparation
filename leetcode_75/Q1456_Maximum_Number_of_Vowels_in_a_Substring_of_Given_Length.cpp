#include <string>
#include <algorithm>

class Solution {
public:
    int maxVowels(string s, int k) {
        // init
        int count = 0;
        for (std::size_t i = 0; i < s.size() && i < k; ++i) {
            if (is_vowel(s[i])) count++;
        }
        int res = count;
        for (std::size_t i = 0; i < s.size() - k; ++i) {
            if (is_vowel(s[i]))
                count--;
            if (is_vowel(s[i + k])) {
                count++;
            }
            res = std::max(count, res);
        }
        return res;
    }

    bool is_vowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        return false;
    }
};