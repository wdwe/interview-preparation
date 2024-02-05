#include <vector>
#include <iostream>

using std::vector;
template<class T> std::ostream& operator<<(std::ostream& os, vector<vector<T>> vvt) {
    for (auto it = vvt.cbegin(); it != vvt.cend(); ++it) {
        if (it != vvt.cbegin()) os << std::endl;
        for (auto it2 = it->cbegin(); it2 != it->cend(); ++it2) {
            if (it2 != it->cbegin()) os << ", ";
            os << *it2;
        }
    }
    return os;
}


class Solution {
public:
    void solve(vector<vector<char>>& board) {
        H = board.size();
        W = board[0].size();
        vis_final.assign(H, vector<bool>(W, false));
        vis.assign(H, vector<bool>(W, false));
        for (std::size_t y = 0; y < H; ++y) {
            for (std::size_t x = 0; x < W; ++x) {
                if (board[y][x] == 'X' || vis_final[y][x]) continue;
                surrounded = true;
                first_round = true;
                dfs(x, y, board);
                first_round = false;
                vis.assign(H, vector<bool>(W, false));
                dfs(x, y, board);
            }
        }
    }
private:
    vector<vector<bool>> vis_final, vis;
    std::size_t H = 0, W = 0;
    bool first_round = true;
    bool surrounded = true;

    void dfs(std::size_t x, std::size_t y, vector<vector<char>>& board) {
        if (vis[y][x] || board[y][x] == 'X') return;

        vis[y][x] = true;
        if (x != 0 && x - 1 >= 0) dfs(x - 1, y, board);
        else surrounded = false;
        if (x + 1 < W) dfs(x + 1, y, board);
        else surrounded = false;
        if (y != 0 && y - 1 >= 0) dfs(x, y - 1, board);
        else surrounded = false;
        if (y + 1 < H) dfs(x, y + 1, board);
        else surrounded = false;
        std::cout << board << std::endl;
        if (!first_round) {
            vis_final[y][x] = true;
            if (surrounded) board[y][x] = 'X';
        }
    }
};

int main() {
    vector<vector<char>> board = {
            {'X', 'X', 'X', 'X'},
            {'X', 'O', 'O', 'X'},
            {'X', 'X', 'O', 'X'},
            {'X', 'O', 'X', 'X'},
    };
    Solution sol;
    sol.solve(board);
    std::cout << board << std::endl;
    return 0;
}