#include <stack>
#include <string>
#include <unordered_map>

class Solution {
public:
    static bool isValid(std::string s) {
        std::unordered_map<char, char> map{{')', '('}, {']', '['}, {'}', '{'}};
        std::stack<char> remaining;
        for (char c: s) {
            if (!remaining.empty() && map.contains(c) && map[c] == remaining.top()) remaining.pop();
            else remaining.push(c);
        }
        return remaining.empty();
    }
};