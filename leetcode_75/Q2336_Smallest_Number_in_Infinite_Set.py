from heapq import heappush, heappop


class SmallestInfiniteSet:

    def __init__(self):
        self.add_back = set()
        self.smallest_added_back = []
        self.present = 1

    def popSmallest(self) -> int:
        if self.smallest_added_back:
            ret = heappop(self.smallest_added_back)
            self.add_back.remove(ret)
        else:
            ret = self.present
            self.present += 1
        return ret

    def addBack(self, num: int) -> None:
        if num < self.present and num not in self.add_back:
            self.add_back.add(num)
            heappush(self.smallest_added_back, num)


# Your SmallestInfiniteSet object will be instantiated and called as such:
# obj = SmallestInfiniteSet()
# param_1 = obj.popSmallest()
# obj.addBack(num)
