class Solution:
    def successfulPairs(
        self, spells: List[int], potions: List[int], success: int
    ) -> List[int]:
        potions.sort()
        res = []
        for sp in spells:
            min_strn = success / sp
            idx = self.binary_search(potions, 0, len(potions), min_strn)
            res.append(len(potions) - idx)

        return res

    def binary_search(self, arr, i, j, val):
        while i != j:
            mid = i + (j - i) // 2
            if arr[mid] < val:
                i = mid + 1
            else:
                j = mid
        return j
