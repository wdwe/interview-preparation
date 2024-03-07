#include <string>
// #include <unordered_map>
// #include <unordered_set>
#include <vector>

// using std::unordered_map;
using std::vector;
using std::string;
// using std::unordered_set;


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        std::vector<bool> breakable(s.size(), false);
        for (int i = 0; i < s.size(); ++i) {
            for (const auto &word: wordDict) {
                if ((i + 1) < word.size())
                    continue;
                if ((i + 1) > word.size() && !breakable[i - word.size()])
                    continue;
                if (s.compare(i + 1 - word.size(), word.size(), word) == 0)
                    breakable[i] = true;
            }
        }
        return breakable[breakable.size() - 1];

    }


};