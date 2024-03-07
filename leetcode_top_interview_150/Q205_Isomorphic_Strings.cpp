#include <string>
#include <unordered_map>

class Solution {
public:
    static bool isIsomorphic(std::string s, std::string t) {
        std::unordered_map<char, char> map_s, map_t;
        if (s.size() != t.size()) return false;
        for (std::size_t i = 0; i < s.size(); ++i) {
            if (map_s.contains(s[i])) {
                if (map_s[s[i]] != t[i])
                    return false;
            }
            else {
                if (map_t.contains(t[i])) return false;
                map_s[s[i]] = t[i];
                map_t[t[i]] = s[i];
            }
        }
        return true;
    }
};