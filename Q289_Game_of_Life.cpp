#include <vector>

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

class Solution {
public:
    static void gameOfLife(vvi& board) {
        int H = static_cast<int>(board.size()), W = static_cast<int>(board.back().size());
        for (int y = 0; y < H; ++y) {
            for (int x = 0; x < W; ++x) {
                int num_live = count_live_neigh(board, x, y);
                if (board[y][x] == live && (num_live < 2 || num_live > 3)) board[y][x] = to_die;
                else if (board[y][x] == dead && num_live == 3) board[y][x] = to_live;
            }
        }

        for (int y = 0; y < H; ++y) {
            for (int x = 0; x < W; ++x) {
                if (board[y][x] == to_live) board[y][x] = live;
                else if (board[y][x] == to_die) board[y][x] = dead;
            }
        }

    }

private:
    static const int live = 1, dead = 0, to_live = 4, to_die = 3; // integral values can be init here
    static bool is_live(int v) {
        return v == live || v == to_die;
    }
    static int count_live_neigh(vvi& board, int x, int y) {
        int H = static_cast<int>(board.size()), W = static_cast<int>(board.back().size());
        int count = 0;
        for (int offset_y: {-1, 0, 1}) {
            for (int offset_x: {-1, 0, 1}) {
                if (offset_x == 0 && offset_y == 0) continue;
                int n_x = x + offset_x, n_y = y + offset_y;
                if (n_x >= 0 && n_x < W && n_y >= 0 && n_y < H && is_live(board[n_y][n_x]))
                    ++count;
            }
        }
        return count;
    }
};