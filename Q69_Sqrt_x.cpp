class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = (1 << 16) - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            unsigned int power = static_cast<unsigned int>(mid) * mid;
            if (power < x) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        int sqrt = l;
        unsigned int power = static_cast<unsigned int>(sqrt) * sqrt;

        if (power <= x)
            return sqrt;
        else
            return sqrt - 1;
    }
};