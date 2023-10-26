from typing import List


class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        num_moves = 0
        start_pos = 0

        while num_moves < len(nums):
            curr_pos = start_pos
            prev_value = nums[curr_pos]

            while True:
                future_pos = (curr_pos + k) % len(nums)
                _tmp = nums[future_pos]
                nums[future_pos] = prev_value
                prev_value = _tmp
                curr_pos = future_pos
                num_moves += 1
                if curr_pos == start_pos:
                    break
            start_pos += 1

