class Solution:
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        graph = [[] for _ in range(n)]
        for u, v in connections:
            graph[u].append((v, False))
            graph[v].append((u, True))

        stack = []
        stack.append(0)
        res = 0
        seen = [False] * n
        while stack:
            city = stack.pop()
            seen[city] = True
            for v, forward in graph[city]:
                if not seen[v]:
                    stack.append(v)
                    res += (not forward)
        return res
