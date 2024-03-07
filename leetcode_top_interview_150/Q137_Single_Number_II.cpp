class Solution {
public:
    // number    : 1 --|
    //                 | XOR seen once-------|
    // seen_once : 0 <-|                     | but not twice (&)
    // seen_twice: 0 <-----------------------|
    // 
    // the central idea is that only one bit at the same position can be turned on
    // if all other bits are 0 at the moment of update, then the bit can be turned on
    // we need to follow the order of 1, 2, 3, 4 ...times when updating

    int singleNumber(vector<int>& nums) {
        int seen_once = 0, seen_twice = 0;
        for (int n: nums) {
            seen_once = (seen_once ^ n) & (~seen_twice);
            seen_twice = (seen_twice ^ n) & (~seen_once);
        }
        return seen_once;
    }
};