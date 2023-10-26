from typing import List


class Solution:
    def hIndex(self, citations: List[int]) -> int:
        # citations.sort(reverse=True)
        # for i in range(len(citations)):
        #     if i + 1 > citations[i]:
        #         return i
        # return len(citations)
        counts = [0] * len(citations)
        for c in citations:
            if c != 0:
                i = min(c - 1, len(citations) - 1)
                counts[i] += 1
        for i in range(len(citations) - 2, -1, -1):
            counts[i] += counts[i + 1]
        for i in range(len(citations) - 1, -1, -1):
            if counts[i] >= i + 1:
                return i + 1
        return 0
