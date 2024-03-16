// you can use includes, for example:
#include <algorithm>
#include <vector>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

using namespace std;

int solution(vector<int> &A) {
    // Implement your solution here
    vector<int> forward(A.size(), 0);
    vector<int> backword(A.size(), 0);
    int curr = 0;
    for (size_t i = 1; i < A.size(); ++i) {
        curr += A[i];
        curr = max(curr, 0);
        forward[i] = curr;
    }
    curr = 0;
    for (int i = A.size() - 2; i >= 0; --i) {
        curr += A[i];
        curr = max(curr, 0);
        backword[i] = curr;
    }
    int max_sum = 0;
    for (size_t i = 1; i < A.size() - 1; ++i) {
        max_sum = max(max_sum, forward[i - 1] + backword[i + 1]);
    }
    return max_sum;
}

/*
 * O(n) time, O(1) space solution
 * but did not make it work completely
 */

// // you can use includes, for example:
//#include <algorithm>
//#include <climits>
//
//using namespace std;
//
// // you can write to stdout for debugging purposes, e.g.
// // cout << "this is a debug message" << endl;
//
//int solution(vector<int> &A) {
//    // Implement your solution here
//    int curr_sum = A[1];
//    int curr_min = A[1];
//    int max_sum = 0;
//    for (size_t i = 2; i < A.size() - 1; ++i) {
//        if (curr_sum < 0) {
//            curr_sum = 0;
//            curr_min = INT_MAX;
//        }
//        curr_min = min(curr_min, A[i]);
//        curr_sum += A[i];
//        max_sum = max(curr_sum - curr_min, max_sum);
//    }
//    return max_sum;
//}


