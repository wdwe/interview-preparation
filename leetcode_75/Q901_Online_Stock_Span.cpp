#include <vector>
#include <utility>

using std::vector;
using std::pair;

class StockSpanner {
public:
    StockSpanner() {

    }

    int next(int price) {
        int span = 1;
        while (!stack.empty() && stack.back().first <= price) {
            span += stack.back().second;
            stack.pop_back();
        }
        stack.emplace_back(price, span);
        return span;
    }
private:
    vector<pair<int, int>> stack;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */