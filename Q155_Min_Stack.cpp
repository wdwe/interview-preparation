#include <vector>

class MinStack {
public:
    MinStack() {

    }

    void push(int val) {
        stack.push_back(val);
        if (min_values.empty()) min_values.push_back(val);
        else min_values.push_back(min_values.back() < val ? min_values.back(): val);
    }

    void pop() {
        stack.pop_back();
        min_values.pop_back();
    }

    int top() {
        return stack.back();
    }

    int getMin() {
        return min_values.back();
    }
private:
    std::vector<int> min_values;
    std::vector<int> stack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */