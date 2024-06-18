#include <vector>
#include <utility>

using std::vector;
using std::pair;
using std::size_t;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<pair<int, int>> stack;
        vector<int> res(temperatures.size(), 0);
        stack.emplace_back(0, temperatures[0]);
        for (int i = 1; i < temperatures.size(); ++i) {
            while (!stack.empty() && stack.back().second < temperatures[i]) {
                res[stack.back().first] = i - stack.back().first;
                stack.pop_back();
            }
            stack.emplace_back(i, temperatures[i]);
        }
        return res;
    }
};