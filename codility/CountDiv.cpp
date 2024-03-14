// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int A, int B, int K) {
    // Implement your solution here
    if (A % K)
        A = A + K - (A % K);
    B = B - (B % K);
    if (A > B)
        return 0;
    return (B - A) / K + 1;
}