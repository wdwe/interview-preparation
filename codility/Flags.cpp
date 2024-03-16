// you can use includes, for example:
#include <algorithm>
#include <vector>

using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int num_flags(vector<int> &P, int K) {
    int f = 1;
    int last = P[0];
    for (size_t i = 1; i < P.size(); ++i) {
        if (P[i] - last >= K){
            last = P[i];
            ++f;
        }
    }
    return f;
}

int solution(vector<int> &A) {
    // Implement your solution here
    vector<int> peaks;
    for (size_t p = 1; p < A.size() - 1; ++p) {
        if (A[p] > A[p - 1] && A[p] > A[p + 1])
            peaks.push_back(p);
    }
    // binary search
    if (peaks.size() == 0)
        return 0;
    int l = 0, r = peaks.size() + 1, res = 0;
    // cout << "num_peaks:" << peaks.size() << endl;
    while (l < r) {
        int mid = l + (r - l) / 2;
        int num = num_flags(peaks, mid);
        // cout << "left:" << l << "right:" << r << " mid:" << mid << " num:" << num << endl;
        if (num < mid) {
            r = mid;
        } else {
            l = mid + 1;
            res = mid;
        }
    }

    return res;
}