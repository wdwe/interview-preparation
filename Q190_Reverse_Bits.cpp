#include <bitset>
#include <string>
#include <algorithm>
#include <cstdint>

using std::bitset;
using std::string;


class Solution {
public:

    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; ++i) {
            res <<= 1;
            int b = n & 1;
            n >>= 1;
            res += b;
        }
        return res;
    }

    // using library
    // uint32_t reverseBits(uint32_t n) {
    //     bitset<32> bits(n);
    //     string s = bits.to_string();
    //     std::reverse(s.begin(), s.end());
    //     bitset<32> r_bits(s);
    //     return r_bits.to_ulong();
    // }
};