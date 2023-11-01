#include <string>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

class Solution {
public:
    static bool wordPattern(std::string pattern, std::string s) {
        std::unordered_map<char, std::string> map;
        std::unordered_set<std::string> seen;
        std::istringstream stream(s);
        std::string substr;
        int i = 0;
        while(stream >> substr) {
            if (i == pattern.size()) return false;
            char p = pattern[i];
            if (map.contains(p)) {
                if (substr != map[p])
                    return false;
            } else {
                if (seen.contains(substr)) return false;
                map[p] = substr;
                seen.insert(substr);
            }
            ++i;
        }
        if (i != pattern.size()) return false;
        return true;
    }
};