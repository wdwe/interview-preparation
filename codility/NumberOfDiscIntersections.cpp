// you can use includes, for example:
#include <algorithm>
#include <vector>
#include <utility>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

using namespace std;

int solution(vector<int> &A) {
    // Implement your solution here
    vector<pair<long long, int>> range;
    for (size_t i = 0; i < A.size(); ++i) {
        long long center = i;
        range.emplace_back(center - A[i], 0);
        range.emplace_back(center + A[i], 1);
    }
    sort(range.begin(), range.end());
    int count = 0;
    int num = 0;
    for (size_t i = 0; i < range.size(); ++i) {
        auto p = range[i];
        if (p.second == 0) {
            num += count;
            count++;
        } else {
            count--;
        }
        if (num > 10000000)
            return -1;
    }
    return num;
}