#include <vector>

class Solution {
public:
    std::vector<int> asteroidCollision(std::vector<int>& asteroids) {
        std::vector<int> st;
        for (int ast: asteroids) {
            if (st.empty()) {
                st.push_back(ast);
            } else {
                bool push = true;
                while (ast < 0 && !st.empty() && st.back() > 0) {
                    if (ast + st.back() < 0)
                        st.pop_back();
                    else {
                        if (ast + st.back() == 0) {
                            st.pop_back();
                        }
                        push = false;
                        break;
                    }
                }
                if (push)
                    st.push_back(ast);
            }
        }
        return st;
    }
};