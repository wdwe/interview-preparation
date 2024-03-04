class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while (right > left) {
            right &= (right - 1);
        }
        return right & left;
    }

    // int rangeBitwiseAnd(int left, int right) {
    //     int res = 0;
    //     for (int shift = 31; shift >= 0; shift--) {
    //         int mask = (1 << shift);
    //         int i = (mask & right);
    //         int j = (mask & left);
    //         if (i ^ j)
    //             break;
    //         res += i & j; 
    //     }
    //     return res;
    // }
};