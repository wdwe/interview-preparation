class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        results = []
        prefix = []
        self.recurse(results, prefix, 0, n, k, 1)
        return results

    def recurse(self, results, prefix, prefix_sum, target, k, num):
        if prefix_sum > target:
            return
        if k == 0:
            if prefix_sum == target:
                results.append(prefix[:])
            return
        if num == 10:
            return

        prefix.append(num)
        self.recurse(results, prefix, prefix_sum + num, target, k - 1, num + 1)
        prefix.pop()
        self.recurse(results, prefix, prefix_sum, target, k, num + 1)
