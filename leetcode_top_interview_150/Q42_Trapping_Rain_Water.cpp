#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        int l_ptr = 0, r_ptr = height.size() - 1, l_max = 0, r_max = 0, total = 0;
        while (r_ptr >= l_ptr) {
            if (l_max < r_max) {
                int curr = height.at(l_ptr);
                if (curr > l_max) l_max = curr;
                else total += l_max - curr;
                ++l_ptr;
            } else {
                int curr = height.at(r_ptr);
                if (curr > r_max) r_max = curr;
                else total += r_max - curr;
                --r_ptr;
            }
        }
        return total;
    }
};