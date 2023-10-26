#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        while (i < j) {
            int sum = numbers.at(i) + numbers.at(j);
            if (sum == target) return vector<int>({i + 1, j + 1});
            if (sum > target) --j;
            else ++i;
        }
        return vector<int>({i + 1, j + 1});
    }
};