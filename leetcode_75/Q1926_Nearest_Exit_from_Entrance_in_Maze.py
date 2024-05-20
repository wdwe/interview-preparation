from collections import deque

class Solution:
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        self.h = len(maze)
        self.w = len(maze[0])
        self.entrance = entrance
        self.vis = [[False] * self.w for _  in range(self.h)]
        q = deque()
        r, c = entrance
        q.append((r, c, 0))
        self.vis[r][c] = True

        while q:
            r, c, steps = q.popleft()
            if self.is_exit(r, c):
                return steps
            steps += 1
            if r - 1 >= 0 and not self.vis[r - 1][c] and maze[r - 1][c] == ".":
                q.append((r - 1, c, steps))
                self.vis[r - 1][c] = True
            if r + 1 < self.h and not self.vis[r + 1][c] and maze[r + 1][c] == ".":
                q.append((r + 1, c, steps))
                self.vis[r + 1][c] = True
            if c - 1 >= 0 and not self.vis[r][c - 1] and maze[r][c - 1] == ".":
                q.append((r, c - 1, steps))
                self.vis[r][c - 1] = True
            if c + 1 < self.w and not self.vis[r][c + 1] and maze[r][c + 1] == ".":
                q.append((r, c + 1, steps))
                self.vis[r][c + 1] = True

        return -1


    def is_exit(self, r, c):
        if r == self.entrance[0] and c == self.entrance[1]:
            return False
        return r == 0 or r == self.h - 1 or c == 0 or c == self.w - 1

