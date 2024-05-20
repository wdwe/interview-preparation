from collections import deque


class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        q = deque()
        rows = len(grid)
        cols = len(grid[0])
        vis = [[False] * cols for _ in range(rows)]
        offsets = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        fresh = 0
        for r, row in enumerate(grid):
            for c, orange in enumerate(row):
                if orange == 1:
                    fresh += 1
                elif orange == 2:
                    q.append((r, c, 0))
                    vis[r][c] = True
        if not fresh:
            return 0

        while q:
            r, c, step = q.popleft()
            next_step = step + 1
            for r_off, c_off in offsets:
                neigh_r, neigh_c  = r + r_off, c + c_off
                if neigh_r >= 0 and neigh_r < rows and neigh_c >= 0 and neigh_c < cols:
                    if not vis[neigh_r][neigh_c] and grid[neigh_r][neigh_c] == 1:
                        vis[neigh_r][neigh_c] = True
                        fresh -= 1
                        q.append((neigh_r, neigh_c, next_step))
            if not fresh:
                return next_step

        return -1
