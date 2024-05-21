class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        col = [int(text1[0] == text2[0])]
        for c in text1[1:]:
            if c == text2[0]:
                col.append(1)
            else:
                col.append(col[-1])

        for c in text2[1:]:
            diag = None
            for i in range(len(text1)):
                # store old diag
                if text1[i] == c:
                    if diag is not None:
                        diag, col[i] = col[i], diag + 1
                    else:
                        diag = col[i]
                        col[i] = 1
                else:
                    diag = col[i]
                    col[i] = max(col[i], col[i - 1]) if i > 0 else col[i]
        return col[-1]
