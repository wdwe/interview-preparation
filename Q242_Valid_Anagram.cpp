#include <string>
#include <unordered_map>

class Solution {
public:
    static bool isAnagram(std::string s, std::string t) {
        std::unordered_map<char, int> map_s, map_t;
        for (char c: s) ++map_s[c];
        for (char c: t) ++map_t[c];
        for (auto &[k, v]: map_s) {
            if (!(map_t.contains(k) && map_t[k] == v)) return false;
        }
        for (auto &[k, v]: map_t) {
            if (!(map_s.contains(k) && map_s[k] == v)) return false;
        }
        return true;
    }
};