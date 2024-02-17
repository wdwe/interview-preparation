#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int y = 0; y < board.size(); ++y) {
            for (int x = 0; x < board[0].size(); ++x) {
                if (backtrack(board, word, y, x, 0)) return true;
            }
        }
        return false;
    }

    bool backtrack(vector<vector<char>>& board, string word, int y, int x, int idx) {
        if (idx == word.size())
            return true;
        if (y < 0 || x < 0 || y >= board.size() || x >= board[0].size())
            return false;
        if (board[y][x] == word[idx]) {
            char c = board[y][x];
            board[y][x] = '*';
            if (backtrack(board, word, y - 1, x, idx + 1)) return true;
            if (backtrack(board, word, y + 1, x, idx + 1)) return true;
            if (backtrack(board, word, y, x - 1, idx + 1)) return true;
            if (backtrack(board, word, y, x + 1, idx + 1)) return true;
            board[y][x] = c;
        }
        return false;
    }
};