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
//#include <vector>
// // you can write to stdout for debugging purposes, e.g.
// // cout << "this is a debug message" << endl;
//
//using namespace std;
//
//int solution(vector<int> &A) {
//    // Implement your solution here
//    int min_num;
//    int curr = 0;
//    int max_sum = 0;
//    // init (0, 1, 2)
//    max_sum = 0;
//    size_t i = 1;
//    while (i < A.size() - 1) {
//        if (A[i] < 0)
//            i++;
//        else
//            break;
//    }
//    min_num = A[i];
//    i++;
//    while (i < A.size() - 1 ) {
//        if (A[i] < min_num) {
//            curr += min_num;
//            min_num = A[i];
//        } else {
//            curr += A[i];
//        }
//        max_sum = max(max_sum, curr);
//        if (curr < 0){
//            while (i < A.size() - 1) {
//                if (A[i] < 0)
//                    i++;
//                else
//                    break;
//            }
//            curr = 0;
//            min_num = A[i];
//        }
//        i++;
//    }
//    return max_sum;
//}

