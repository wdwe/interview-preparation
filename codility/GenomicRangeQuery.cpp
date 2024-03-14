// you can use includes, for example:
// #include <algorithm>
#include <vector>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

using namespace std;

int to_factor(char c) {
    if (c == 'A')
        return 1;
    if (c == 'C')
        return 2;
    if (c == 'G')
        return 3;
    return 4;
}

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    // Implement your solution here
    vector<vector<int>> prefix(4, vector<int>(1, 0));

    for (char c: S) {
        for (auto &v: prefix) {
            v.push_back(v.back());
        }
        int factor = to_factor(c);
        prefix[factor - 1].back()++;
    }

    vector<int> res;
    for (size_t i = 0; i < P.size(); ++i) {
        int st = P[i], end = Q[i] + 1;
        if (prefix[0][end] - prefix[0][st] > 0)
            res.push_back(1);
        else if (prefix[1][end] - prefix[1][st] > 0)
            res.push_back(2);
        else if (prefix[2][end] - prefix[2][st] > 0)
            res.push_back(3);
        else
            res.push_back(4);
    }
    return res;
}