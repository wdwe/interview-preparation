#include <string>
#include <vector>

using std::vector;
using std::string;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<vector<char>> mapping = {
                {},
                {},
                {'a', 'b', 'c'},
                {'d', 'e', 'f'},
                {'g', 'h', 'i'},
                {'j', 'k', 'l'},
                {'m', 'n', 'o'},
                {'p', 'q', 'r', 's'},
                {'t', 'u', 'v'},
                {'w', 'x', 'y', 'z'}
        };
        vector<string> results;
        int n = digits[0] - '0';
        for (auto c: mapping[n])
            results.emplace_back(1, c);

        int count = results.size();
        for (int i = 1; i < digits.size(); ++i) {
            int num = digits[i] - '0';
            for (int j = 0; j < mapping[num].size(); ++j) {
                if (j == mapping[num].size() - 1) {
                    for (int k = 0; k < count; ++k) {
                        results[k].push_back(mapping[num][j]);
                    }
                } else {
                    for (int k = 0; k < count; ++k) {
                        results.emplace_back(results[k] + mapping[num][j]);
                    }
                }
            }
            count = results.size();
        }
        return results;
    }
};