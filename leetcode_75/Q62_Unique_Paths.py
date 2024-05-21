class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        col = [1] * n
        for _ in range(1, m):
            for i in range(n):
                col[i] += col[i - 1] if i > 0 else 0
        return col[-1]
