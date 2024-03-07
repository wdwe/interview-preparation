
class Solution {
public:
    int trailingZeroes(int n) {
        // trailing zeros means 2, 5 and 10
        // where 2 and 5 can be paired to form 10
        // since at any time, we have more 2 than 5, we just need to 
        // and 10 can be factorised in to 5 check number of 5 

        int zeros = 0;
        int five_power = 1;
        while (five_power <= n) {
            five_power = five_power * 5;
            zeros += n / five_power;
        }

        return zeros;

    }
};