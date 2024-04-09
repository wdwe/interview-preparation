#include <vector>
#include <string>

class Solution {
public:
    int compress(vector<char>& chars) {
        std::size_t i = 0, cnt = 0;
        char ch = chars[0];
        cnt += 1;
        for (std::size_t j = 1; j < chars.size(); ++j) {
            if (chars[j] == ch) {
                cnt += 1;
            } else {
                chars[i++] = ch;
                if (cnt > 1) {
                    std::string s = std::to_string(cnt);
                    for (char c: s) {
                        chars[i++] = c;
                    }
                }
                cnt = 1;
                ch = chars[j];
            }
        }
        chars[i++] = ch;
        if (cnt > 1) {
            std::string s = std::to_string(cnt);
            for (char c: s) {
                chars[i++] = c;
            }
        }
        return i;
    }
};