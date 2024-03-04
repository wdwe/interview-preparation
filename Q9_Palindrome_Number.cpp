class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        unsigned int r_num = 0;
        int num = x;
        while (num) {
            r_num *= 10;
            r_num += num % 10;
            num = num / 10;
        }
        return (x == r_num);
    }
};