#include <string>
#include <unordered_map>

class Solution {
public:
    static bool canConstruct(std::string ransomNote, std::string magazine) {
        std::unordered_map<char, int> mag;
        for (char c: magazine) ++mag[c];
        for (auto it = ransomNote.cbegin(); it != ransomNote.cend(); ++it) {
            if (mag.contains(*it) && mag[*it] > 0) --mag[*it];
            else return false;
        }
        return true;
    }
};