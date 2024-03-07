class Solution {
public:
    int climbStairs(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;

        int prev_one = 2;
        int prev_two = 1;
        int res = 0;
        for (int i = 2; i < n; ++i) {
            res = prev_one + prev_two;
            prev_two = prev_one;
            prev_one = res;
        }
        return res;
    }
};