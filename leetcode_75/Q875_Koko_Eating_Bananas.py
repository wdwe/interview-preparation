import math


class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        max_k = max(piles)
        min_k = 1
        while max_k != min_k:
            k = min_k + (max_k - min_k) // 2
            t = sum(math.ceil(p / k) for p in piles)
            if t > h:
                min_k = k + 1
            else:
                max_k = k
        return max_k
