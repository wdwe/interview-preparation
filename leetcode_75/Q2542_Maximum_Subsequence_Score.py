from heapq import heappush, heappop


class Solution:
    def maxScore(self, nums1: List[int], nums2: List[int], k: int) -> int:
        nums = list(zip(nums1, nums2))
        nums.sort(key=lambda x: x[1], reverse=True)
        seq = []
        for i in range(k):
            heappush(seq, nums[i][0])
        seq_sum = sum(seq)
        max_sum = nums[k - 1][1] * seq_sum
        for i in range(k, len(nums)):
            seq_sum -= heappop(seq)
            heappush(seq, nums[i][0])
            seq_sum += nums[i][0]
            max_sum = max(max_sum, seq_sum * nums[i][1])
        return max_sum
