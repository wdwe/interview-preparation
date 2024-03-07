#include <vector>
#include <limits>
#include <algorithm>

using std::vector;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> costs(k, std::numeric_limits<int>::max());
        vector<int> profits(k, 0);
        for (int price: prices) {
            costs[0] = std::min(costs[0], price);
            profits[0] = std::max(profits[0], price - costs[0]);
            for (int i = 1; i < k; i++) {
                costs[i] = std::min(costs[i], price - profits[i - 1]);
                profits[i] = std::max(profits[i], price - costs[i]);
            }
        }
        return profits[k - 1];
    }
};