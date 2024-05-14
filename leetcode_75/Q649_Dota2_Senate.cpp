#include <queue>
#include <string>

class Solution {
public:
    std::string predictPartyVictory(std::string senate) {
        std::queue<char> Q;
        std::size_t r_count = 0, d_count = 0, r_ban = 0, d_ban = 0;
        for (char c: senate) {
            Q.push(c);
            if (c == 'R')
                r_count++;
            else
                d_count++;
        }
        while (!Q.empty()) {
            if (r_count == 0)
                return "Dire";
            if (d_count == 0)
                return "Radiant";
            char s = Q.front();
            Q.pop();
            if (s == 'R') {
                if (r_ban > 0)
                    r_ban--;
                else {
                    d_ban++;
                    d_count--;
                    Q.push(s);
                }
            } else {
                if (d_ban > 0)
                    d_ban--;
                else {
                    r_ban++;
                    r_count--;
                    Q.push(s);
                }
            }
        }
        return "";
    }
};