from typing import List


class Solution:
    def jump(self, nums: List[int]) -> int:
        # min_steps = [float("inf")] * len(nums)
        # min_steps[-1] = 0
        # for pos in range(len(nums) - 2, -1, -1):
        #     jump_end = min(len(nums) - 1, pos + nums[pos])
        #     min_steps[pos] = min(min_steps[pos: jump_end + 1]) + 1
        # return min_steps[0]

        max_pos = 0
        curr_range = 0
        num_jumps = 0
        for i in range(len(nums) - 1):
            max_pos = max(max_pos, i + nums[i])
            if i == curr_range:
                curr_range = max_pos
                num_jumps += 1
        return num_jumps