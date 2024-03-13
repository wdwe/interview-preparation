// you can use includes, for example:
#include <algorithm>
#include <vector>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

using namespace std;

int solution(vector<int> &A) {
    // Implement your solution here
    vector<int> A1(A);
    sort(A1.begin(), A1.end());
    int smallest = 0;
    for (int v: A1) {
        if (v > 0) {
            if (v == smallest)
                continue;
            if (v != smallest + 1) {
                return smallest + 1;
            } else
                smallest++;
        }
    }
    return smallest + 1;
}