from typing import List

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if len(nums1) > len(nums2):
            return self.findMedianSortedArrays(nums2, nums1)
        total_len = len(nums1) + len(nums2)
        num_left = (total_len) // 2

        start = 0
        end = len(nums1)
        while start <= end:
            mid_1 = (start + end) // 2
            mid_2 = num_left - mid_1
            left_value_1 = nums1[mid_1 - 1] if mid_1 > 0 else float("-inf")
            left_value_2 = nums2[mid_2 - 1] if mid_2 > 0 else float("-inf")
            right_value_1 = nums1[mid_1] if (mid_1) < len(nums1) else float("inf")
            right_value_2 = nums2[mid_2] if (mid_2) < len(nums2) else float("inf")
            if left_value_1 <= right_value_2 and left_value_2 <= right_value_1:
                # we have reached the ans
                if total_len % 2: # if it is odd
                    return min(right_value_1, right_value_2)
                else:
                    # if (mid_1 + 1) >= len(nums1):
                    #     right_value_1 = max(left_value_1, left_value_2)
                    # if (mid_2 + 1) >= len(nums2):
                    #     right_value_2 = max(left_value_1, left_value_2)
                    return (max(left_value_1, left_value_2) + min(right_value_1, right_value_2)) / 2

            # decide direction to move
            if left_value_1 > right_value_2:
                end = mid_1 - 1
            else:
                start = mid_1 + 1
        # if the condition is not satisfied after binary search,
        # median is only in the other array
        if start > len(nums1) - 1:
            # nums1 is in the smaller partition
            mid = num_left - len(nums1) - 1
        else:
            mid = num_left - 1

        if total_len % 2: # if it is odd
            ans = nums2[mid]
        else:
            ans = (nums2[mid] + nums2[mid + 1]) / 2
        return ans
        # A, B = nums1, nums2
        # n = len(A)
        # m = len(B)
        # if (n > m):
        #     return self.findMedianSortedArrays(B, A)  # Swapping to make A smaller

        # start = 0
        # end = n
        # realmidinmergedarray = (n + m + 1) // 2

        # while (start <= end):
        #     mid = (start + end) // 2
        #     leftAsize = mid
        #     leftBsize = realmidinmergedarray - mid

        #     # checking overflow of indices
        #     leftA = A[leftAsize - 1] if (leftAsize > 0) else float('-inf')
        #     leftB = B[leftBsize - 1] if (leftBsize > 0) else float('-inf')
        #     rightA = A[leftAsize] if (leftAsize < n) else float('inf')
        #     rightB = B[leftBsize] if (leftBsize < m) else float('inf')

        #     # if correct partition is done
        #     if leftA <= rightB and leftB <= rightA:
        #         if ((m + n) % 2 == 0):
        #             return (max(leftA, leftB) + min(rightA, rightB)) / 2.0
        #         return max(leftA, leftB)

        #     elif (leftA > rightB):
        #         end = mid - 1
        #     else:
        #         start = mid + 1

























