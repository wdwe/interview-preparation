#include <vector>
using std::vector;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return binary_search(matrix, 0, matrix.size() * matrix[0].size(), target);
    }

    bool binary_search(vector<vector<int>> &matrix, int i, int j, int target) {
        if (i == j) return false;
        int mid = (i + j) / 2;
        int y = mid / matrix[0].size();
        int x = mid % matrix[0].size();
        if (matrix[y][x] == target) return true;
        if (matrix[y][x] > target)
            return binary_search (matrix, i, mid, target);
        return binary_search(matrix, mid + 1, j, target);

    }
};