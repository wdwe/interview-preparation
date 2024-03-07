from typing import List


class Solution:
    def canJump(self, nums: List[int]) -> bool:
        # GREEDY
        #     max_reachable_pos = 0
        #     for i in range(len(nums)):
        #         if i > max_reachable_pos:
        #             return False
        #         max_reachable_pos = max(max_reachable_pos, i + nums[i])
        #     return True

        # dynamic
        reachable = [False] * len(nums)
        reachable[-1] = True
        for pos in range(len(nums) - 2, -1, -1):
            jump_dist = nums[pos]
            for _pos in range(pos, min(len(nums), pos + jump_dist + 1)):
                if reachable[_pos]:
                    reachable[pos] = True
                    break
        return reachable[0]

