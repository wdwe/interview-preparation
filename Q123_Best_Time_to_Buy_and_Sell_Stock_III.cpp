#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        vector<int> max_profit_to(prices.size(), 0);
        int min_price = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            min_price = std::min(min_price, prices[i]);
            max_profit_to[i] = std::max(max_profit_to[i - 1], prices[i] - min_price);
        }

        vector<int> max_profit_from(prices.size(), 0);
        int max_price = prices[prices.size() - 1];
        for (int i = prices.size() - 2; i >= 0; --i) {
            max_price = std::max(max_price, prices[i]);
            max_profit_from[i] = std::max(max_profit_from[i + 1], max_price - prices[i]);
        }

        int res = 0;
        for (int i = 0; i < prices.size(); ++i)
            res = std::max(res, max_profit_to[i] + max_profit_from[i]);
        return res;

    }
};