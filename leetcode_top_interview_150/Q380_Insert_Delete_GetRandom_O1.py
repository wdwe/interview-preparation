import random


class RandomizedSet:
    def __init__(self):
        self._pos = {}
        self._list = []

    def insert(self, val: int) -> bool:
        if val in self._pos:
            return False
        self._list.append(val)
        self._pos[val] = len(self._list) - 1
        return True

    def remove(self, val: int) -> bool:
        if val not in self._pos:
            return False
        pos = self._pos[val]
        last_val = self._list[-1]
        self._pos[last_val] = pos
        self._list[pos], self._list[-1] = self._list[-1], self._list[pos]
        del self._pos[val]
        del self._list[-1]
        return True

    def getRandom(self) -> int:
        val = random.choice(self._list)
        return val



# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()