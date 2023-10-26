#include <vector>
#include <unordered_set>


class Solution {
public:
    static bool isValidSudoku(std::vector<std::vector<char>>& board);

private:
    static bool seen_before(char c);
    static std::unordered_set<char> seen;
};

std::unordered_set<char> Solution::seen;

bool Solution::seen_before(char c) {
    if (seen.contains(c)) return true;
    if (c != '.') seen.insert(c);
    return false;
}

bool Solution::isValidSudoku(std::vector<std::vector<char>> &board) {
    // check rows
    for (auto &row: board) {
        seen.clear();
        for (int j = 0; j < board.front().size(); ++j) {
            char c = row.at(j);
            if (seen_before(c)) return false;
        }
    }

    // check cols
    for (int j = 0; j < board.front().size(); ++j) {
        seen.clear();
        for (auto &row: board) {
            char c = row.at(j);
            if (seen_before(c)) return false;
        }
    }

    // check squares
    for (int r_offset = 0; r_offset < board.size(); r_offset += 3) {
        for (int c_offset = 0; c_offset < board.size(); c_offset += 3) {
            seen.clear();
            for (int r = 0; r < 3; ++r) {
                for (int c = 0; c < 3; ++c) {
                    char ch = board.at(r_offset + r).at(c_offset + c);
                    if (seen_before(ch)) return false;
                }
            }
        }
    }
    return true;
}