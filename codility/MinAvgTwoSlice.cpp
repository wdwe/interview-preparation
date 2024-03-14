// you can use includes, for example:
#include <algorithm>
#include <vector>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

using namespace std;

int solution(vector<int> &A) {
    // Implement your solution here
    int prev_sum = A[0] + A[1];
    int min_sum_2 = prev_sum;
    int min_idx_2 = 0;

    for (size_t i = 2; i < A.size(); ++i) {
        prev_sum = prev_sum + A[i] - A[i - 2];
        if (prev_sum < min_sum_2) {
            min_idx_2 = i - 1;
            min_sum_2 = prev_sum;
        }
    }


    if (A.size() >= 3){
        prev_sum = A[0] + A[1] + A[2];
        int min_sum_3 = prev_sum;
        int min_idx_3 = 0;
        for (size_t i = 3; i < A.size(); ++i) {
            prev_sum = prev_sum + A[i] - A[i - 3];
            if (prev_sum < min_sum_3) {
                min_idx_3 = i - 2;
                min_sum_3 = prev_sum;
            }
        }

        double min_avg_2 = static_cast<double>(min_sum_2) / 2;
        double min_avg_3 = static_cast<double>(min_sum_3) / 3;

        // bad double comparison
        if (min_avg_2 < min_avg_3)
            return min_idx_2;
        if (min_avg_2 > min_avg_3)
            return min_idx_3;

        return min(min_idx_2, min_idx_3);
    }
    return min_idx_2;
}