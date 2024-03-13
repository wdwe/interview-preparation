// you can use includes, for example:
#include <algorithm>
#include <vector>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

using namespace std;

vector<int> solution(int N, vector<int> &A) {
    // Implement your solution here
    int curr_max = 0;
    int potential_max = 0;
    vector<int> res(N, 0);
    for (int v: A) {
        if (v > N)
            curr_max = potential_max;
        else {
            res[v - 1] = max(curr_max, res[v - 1]);
            res[v - 1]++;
            potential_max = max(res[v - 1], potential_max);
        }
    }
    for (int& v: res)
        v = max(v, curr_max);
    return res;
}