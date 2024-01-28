#include <vector>
using std::vector;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int H = static_cast<int>(grid.size()), W = static_cast<int>(grid[0].size());
        vector<vector<bool>> visited;
        visited.assign(H, {});
        for (auto &vec: visited) vec.assign(W, false);
        int count = 0;
        for (int r = 0; r < H; ++r)
            for (int c = 0; c < W; ++c) {
                if (visited[r][c] || grid[r][c] != '1' ) continue;
                ++count;
                dfs(r, c, visited, grid, H, W);
            }
        return count;
    }

    void dfs(int r, int c, vector<vector<bool>> &visited, vector<vector<char>> &grid, int H, int W) {
        if (visited[r][c]) return;
        visited[r][c] = true;
        if (r + 1 < H && grid[r + 1][c] == '1') dfs(r + 1, c, visited, grid, H, W);
        if (r - 1 >= 0 && grid[r - 1][c] == '1') dfs(r - 1, c, visited, grid, H, W);
        if (c + 1 < W && grid[r][c + 1] == '1') dfs(r, c + 1, visited, grid, H, W);
        if (c - 1 >= 0 && grid[r][c - 1] == '1') dfs(r, c - 1, visited, grid, H, W);
    }
};