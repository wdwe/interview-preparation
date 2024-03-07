#include <vector>
#include <utility>
#include <queue>
#include <iostream>

using std::vector;
using std::pair;
using std::queue;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        vector<int> flat_board;
        int H = board.size(), W = board[0].size();
        int pos = 0;
        bool flip = false;
        for (int r = H - 1; r >= 0; --r) {
            for (int i = 0; i < W; ++i) {
                int idx;
                if (flip) {
                    idx = board[r][pos--];
                } else {
                    idx = board[r][pos++];
                }
                if (idx > 0) idx--;
                flat_board.push_back(idx);
            }
            if (pos < 0) ++pos;
            else --pos;
            flip = !flip;
        }
        // build graph
        int n = H * W;
        vector<vector<int>> graph(n);
        for (int u = 0; u < n; ++u) {
            for (int v = u + 1; v < u + 7 && v < n; ++v) {
                if (flat_board[v] < 0) graph[u].push_back(v);
                else graph[u].push_back(flat_board[v]);
            }
        }
        // bfs for shortest path
        queue<pair<int, int>> q;
        vector<bool> vis(n);
        vis[0] = true;
        q.emplace(0, 0);
        while (!q.empty()) {
            auto [u, step] = q.front(); q.pop();
            if (u == n - 1) return step;
            for (auto v: graph[u]) {
                if (!vis[v]) {
                    q.emplace(v, step + 1);
                    vis[v] = true;
                }
            }
        }
        return -1;
    }
};


int main() {
    Solution sol;
    vector<vector<int>> board = {
            { -1, -1, -1, -1, -1, -1 },
            { -1, -1, -1, -1, -1, -1 },
            { -1, -1, -1, -1, -1, -1 },
            { -1, 35, -1, -1, 13, -1 },
            { -1, -1, -1, -1, -1, -1 },
            { -1, 15, -1, -1, -1, -1 }
    };
//    vector<vector<int>> board = {
//            {-1,-1}, {-1,3}
//    };
    std::cout << sol.snakesAndLadders(board) << std::endl;


    return 0;
}