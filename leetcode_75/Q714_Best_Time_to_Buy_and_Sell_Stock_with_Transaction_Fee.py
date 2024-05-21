class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        hold = -prices[0] - fee
        not_hold = 0
        for i in range(1, len(prices)):
            new_hold = max(hold, not_hold - fee - prices[i])
            new_not_hold = max(not_hold, hold + prices[i])
            hold = new_hold
            not_hold = new_not_hold
        return not_hold
