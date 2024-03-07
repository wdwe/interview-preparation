class Solution {
public:
    double myPow(double x, int n) {
        long long a = n;
        if (a == 0) return 1;
        if (a < 0)
            return 1 / recur_pow(x, -a);
        return recur_pow(x, a);
    }

    double recur_pow(double x, long long n) {
        if (n == 1)
            return x;
        double res;
        if (n & 1)
            res = recur_pow(x, (n - 1) / 2);
        else
            res = recur_pow(x, n / 2);
        res *= res;
        if (n & 1)
            res *= x;
        return res;

    }
};