// you can use includes, for example:
#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
using namespace std;

int solution(vector<int> &A) {
    // Implement your solution here
    vector<int> nums(A);
    sort(nums.begin(), nums.end());
    int i = 0, j = A.size() - 1;
    int min_sum = INT_MAX;
    int prev;
    while (i <= j) {
        prev = nums[i] + nums[j];
        min_sum = min(min_sum, abs(prev));
        if (prev < 0)
            i++;
        else
            j--;
    }
    return min_sum;
}