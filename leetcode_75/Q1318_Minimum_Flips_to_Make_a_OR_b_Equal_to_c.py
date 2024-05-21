class Solution:
    def minFlips(self, a: int, b: int, c: int) -> int:
        flips = 0
        while a or b or c:
            _a = a & 1
            _b = b & 1
            _c = c & 1
            if (_a | _b) != _c:
                if _c:  # _c is 1
                    flips += 1
                else:
                    flips += _a + _b
            a >>= 1
            b >>= 1
            c >>= 1
        return flips
