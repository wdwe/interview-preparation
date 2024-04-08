// you can use includes, for example:
#include <algorithm>
#include <vector>
#include <functional>


using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

/*
 * Not passing the last correctness test
 */


// get all the factors

vector<int> get_factors(int num) {
    vector<int> factors;
    for (int f = 1; f < num; f++) {
        if (f * f > num)
            break;
        if (num % f == 0) {
            int another = num / f;
            factors.push_back(f);
            if (another != f)
                factors.push_back(another);
        }
    }
    return factors;
}


bool satisfy(vector<int> &peaks, int K, int size) {
    int p = 0;
    for (int l = 0; l < size; l += K) {
        while (peaks[p] < l && p < peaks.size())
            p++;
        if (!(peaks[p] >= l && peaks[p] < l + K))
            return false;
    }
    return true;
}

int solution(vector<int> &A) {
    // Implement your solution here
    vector<int> peaks;
    for (int p = 1; p < A.size() - 1; ++p) {
        if (A[p - 1] < A[p] && A[p + 1] < A[p]) {
            peaks.push_back(p);
        }
    }

    if (peaks.size() == 0) {
        return 0;
    }

    vector<int> factors = get_factors(A.size());
    sort(factors.begin(), factors.end(), greater<>());

    int l = 0, r = factors.size(), res = 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (satisfy(peaks, factors[mid], A.size())) {
            res = A.size() / factors[mid];
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return res;
}