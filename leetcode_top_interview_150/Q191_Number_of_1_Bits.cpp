class Solution {
public:
    // use the trick of (n - 1) & n removes the lsb
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            ++count;
            int m = n - 1;
            n = m & n;
        }
        return count;
    }

    // standard method
    // int hammingWeight(uint32_t n) {
    //     int num = 0;
    //     while (n) {
    //         num += n & 1;
    //         n >>= 1;
    //     }
    //     return num;
    // }
};