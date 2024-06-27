#include <vector>
#include <string>
#include <algorithm>

using std::string;
using std::vector;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> m(s.size(), vector<int>(s.size(), -1));
        return recurse(s, 0, s.size() - 1, m);
    }

    int recurse(const string &s, int i, int j, vector<vector<int>>& m) {
        if (m[i][j] != -1) return m[i][j];
        if (i > j) return 0;
        if (i == j) return 1;

        if (s[i] == s[j]) m[i][j] = recurse(s, i + 1, j - 1, m) + 2;
        else m[i][j] = std::max(recurse(s, i + 1, j, m), recurse(s, i, j - 1, m));

        return m[i][j];
    }
};

// #include <unordered_map>
// #include <functional>
// #include <utility>
// #include <bit>
// #include <string>
// #include <algorithm>


// struct pair_hash {
//     template<class T1, class T2>
//     std::size_t operator() (const std::pair<T1, T2> &p) const {
//         return std::hash<T1>{}(p.first) ^ std::rotr(std::hash<T2>{}(p.second), 1);
//     }
// };

// typedef std::unordered_map<std::pair<std::size_t, std::size_t>, int, pair_hash> pair_map;

// class Solution {
// public:
//     int longestPalindromeSubseq(string s) {
//         pair_map m;
//         return recurse(s, 0, s.size() - 1, m);
//     }

//     int recurse(const std::string &s, std::size_t i, std::size_t j, pair_map &m) {
//         if (i > j) return 0;
//         if (i == j) return 1;
//         // if (i + 1 == j) {
//         //     if (s[i] == s[j]) return 2;
//         //     return 1;
//         // }

//         if (!m.contains({i, j})) {
//             if (s[i] == s[j])
//                 m[{i, j}] = recurse(s, i + 1, j - 1, m) + 2;
//             else
//                 m[{i, j}] = std::max(recurse(s, i, j - 1, m), recurse(s, i + 1, j, m));  
//         }
//         return m[{i, j}];
//     }


// };