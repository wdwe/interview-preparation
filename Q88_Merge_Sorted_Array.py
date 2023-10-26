from typing import List


class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        idx_1 = m - 1
        idx = m + n - 1
        idx_2 = n - 1

        while idx_1 >= 0 and idx_2 >=0:
            if nums1[idx_1] > nums2[idx_2]:
                nums1[idx] = nums1[idx_1]
                idx_1 -= 1
            else:
                nums1[idx] = nums2[idx_2]
                idx_2 -= 1
            idx -= 1
        if idx_1 < 0:
            nums1[0: idx+1] = nums2[0: idx_2+1]

