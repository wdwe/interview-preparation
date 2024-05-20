class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        seen = [False] * len(isConnected)
        stack = []
        stack.append(0)
        province = 0
        for c in range(len(isConnected)):
            if not seen[c]:
                stack.append(c)
                province += 1
                while stack:
                    city = stack.pop()
                    seen[city] = True
                    for _city, conn in enumerate(isConnected[city]):
                        if conn and not seen[_city]:
                            stack.append(_city)
        return province
