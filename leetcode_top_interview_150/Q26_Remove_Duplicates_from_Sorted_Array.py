from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        ptr1, ptr2 = 0, 0
        for ptr3 in range(1, len(nums)):
            if nums[ptr3] != nums[ptr2]:
                nums[ptr1] = nums[ptr2]
                ptr2 = ptr3
                ptr1 += 1
        nums[ptr1] = nums[ptr2]
        ptr1 += 1
        return ptr1