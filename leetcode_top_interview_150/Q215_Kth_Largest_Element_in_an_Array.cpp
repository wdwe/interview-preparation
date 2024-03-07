#include <queue>
#include <vector>
#include <functional>

using std::priority_queue;
using std::vector;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, std::greater<>> pq;
        for (int num: nums) {
            pq.push(num);
            if (pq.size() > k)
                pq.pop();
        }
        return pq.top();
    }
};