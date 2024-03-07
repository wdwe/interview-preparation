from typing import List


class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        ptr1 = 0
        for ptr2 in range(len(nums)):
            if nums[ptr2] != val:
                nums[ptr1] = nums[ptr2]
                ptr1 += 1
        return ptr1