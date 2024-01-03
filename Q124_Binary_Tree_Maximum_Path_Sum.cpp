#include <algorithm>
#include <limits>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        int max_sum, one_side_max;
        max_path(root, max_sum, one_side_max);
        return max_sum;
    }

    void max_path(TreeNode* node, int& max_sum, int& one_side_max) {
        if (!node) {
            max_sum = std::numeric_limits<int>::min();
            one_side_max = std::numeric_limits<int>::min();
            return;
        }
        int max_sum_left, max_sum_right, one_side_left, one_side_right;
        max_path(node->left, max_sum_left, one_side_left);
        max_path(node->right, max_sum_right, one_side_right);
        int connect = (one_side_left > 0? one_side_left: 0) + (one_side_right >0? one_side_right: 0) + node->val;
        one_side_left = one_side_left < 0 ? node->val: one_side_left + node->val;
        one_side_right = one_side_right < 0 ? node->val: one_side_right + node->val;
        max_sum = std::max({max_sum_left, max_sum_right, connect, one_side_right, one_side_left});
        one_side_max = std::max(one_side_left, one_side_right);
    }
};