#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    static int longestConsecutive(std::vector<int>& nums) {
        std::unordered_set<int> unique_nums(nums.cbegin(), nums.cend());
        std::unordered_map<int, int> seqs;
        for (int num: unique_nums) {
            int new_head = num, new_tail = num, tail = num - 1, head = num + 1;
            if (seqs.contains(head)) {
                int t = seqs[head];
                if (t >= head) new_tail = t;
            }
            if (seqs.contains(tail)) {
                int h = seqs[tail];
                if (h <= tail) new_head = h;
            }
            seqs[new_head] = new_tail;
            seqs[new_tail] = new_head;
        }
        int max_len = 0;
        for (auto p: seqs) {
            if (p.second >= p.first) max_len = std::max(max_len, p.second - p.first + 1);
        }
        return max_len;
    }
};