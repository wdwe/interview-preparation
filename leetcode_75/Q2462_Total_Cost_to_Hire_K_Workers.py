from heapq import heappush, heappop


class Solution:
    def totalCost(self, costs: List[int], k: int, candidates: int) -> int:
        front = []
        back = []
        front_idx = 0
        back_idx = len(costs) - 1

        for _ in range(candidates):
            heappush(front, costs[front_idx])
            front_idx += 1
        for _ in range(candidates):
            if back_idx < front_idx:
                break
            heappush(back, costs[back_idx])
            back_idx -= 1

        cost = 0
        for _ in range(k):
            if not back or front and front[0] <= back[0]:
                cost += front[0]
                heappop(front)
                if front_idx <= back_idx:
                    heappush(front, costs[front_idx])
                    front_idx += 1
            else:
                cost += back[0]
                heappop(back)
                if back_idx >= front_idx:
                    heappush(back, costs[back_idx])
                    back_idx -= 1

        return cost
