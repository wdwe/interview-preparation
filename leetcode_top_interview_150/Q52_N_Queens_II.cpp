#include <vector>
#include <unordered_set>

using std::vector;
using std::unordered_set;


class Solution {
// with diagonal trick
public:
    int totalNQueens(int n) {
        unordered_set<int> cols;
        unordered_set<int> diags;
        unordered_set<int> a_diags;
        return backtrack(cols, diags, a_diags, 0, n);
    }

    int backtrack(unordered_set<int>& cols, unordered_set<int>& diags, unordered_set<int>& a_diags, int row, int n) {
        if (row == n)
            return 1;
        int res = 0;
        for (int col = 0; col < n; ++col) {
            int diag = row - col, a_diag = row + col;
            if (cols.contains(col) || diags.contains(diag) || a_diags.contains(a_diag))
                continue;
            cols.insert(col);
            diags.insert(diag);
            a_diags.insert(a_diag);
            res += backtrack(cols, diags, a_diags, row + 1, n);
            cols.erase(col);
            diags.erase(diag);
            a_diags.erase(a_diag);
        }
        return res;
    }


// without diagonal trick
// public:
//     int totalNQueens(int n) {
//         vector<vector<int>> board(n, vector<int>(n));
//         return backtrack(board, 0);
//     }
//     int backtrack(vector<vector<int>>& board, int row) {
//         if (row == board.size())
//             return 1;
//         int res = 0;
//         for (int col = 0; col < board.size(); ++col) {
//             if (board[row][col] == 0) {
//                 update_board(board, row, col, true);
//                 res += backtrack(board, row + 1);
//                 update_board(board, row, col, false);
//             }
//         }
//         return res;
//     }

//     void update_board(vector<vector<int>> &board, int row, int col, bool add) {
//         for (int r = 0; r < board.size(); ++r) {
//             if (add)
//                 board[r][col]++;
//             else
//                 board[r][col]--;
//         }
//         for (int c = 0; c < board.size(); ++c) {
//             if (add)
//                 board[row][c]++;
//             else
//                 board[row][c]--;
//         }
//         int r = row, c = col;
//         while(r >= 0 && c >= 0) {
//             if (add)
//                 board[r--][c--]++;
//             else
//                 board[r--][c--]--;
//         }
//         r = row, c = col;
//         while (r >= 0 && c < board.size()) {
//             if (add)
//                 board[r--][c++]++;
//             else
//                 board[r--][c++]--;
//         }
//         r = row, c = col;
//         while (r < board.size() && c >= 0) {
//             if (add)
//                 board[r++][c--]++;
//             else
//                 board[r++][c--]--;
//         }
//         r = row, c = col;
//         while (r < board.size() && c < board.size()) {
//             if (add)
//                 board[r++][c++]++;
//             else
//                 board[r++][c++]--;
//         }
//     }
};