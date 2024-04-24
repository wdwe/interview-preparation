#include <unordered_map>
#include <string>

class Solution {
public:
    bool closeStrings(std::string word1, std::string word2) {
        std::unordered_map<char, int> cnt1, cnt2;
        for (char c: word1) cnt1[c]++;
        for (char c: word2) cnt2[c]++;

        std::unordered_map<int, int> ccnt1, ccnt2;
        for (auto [k, v]: cnt1) {
            if (!cnt2.contains(k))
                return false;
            ccnt1[v]++;
        }
        for (auto [k, v]: cnt2) {
            if (!cnt1.contains(k))
                return false;
            ccnt2[v]++;
        }
        for (auto [k, v]: ccnt1) {
            if (!ccnt2.contains(k) || ccnt2[k] != v)
                return false;
        }
        return true;
    }
};