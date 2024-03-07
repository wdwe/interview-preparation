#include <cmath>
#include <unordered_set>
#include <string>

class Solution {
public:
    static bool isHappy(int n) {
        std::unordered_set<int> seen{n};
        while (true) {
            std::string str = std::to_string(n);
            n = 0;
            for (char d: str) {
                n += std::pow(d - '0', 2);
            }
            if (n == 1) return true;
            if (seen.contains(n)) return false;
            seen.insert(n);
        }
    }
};