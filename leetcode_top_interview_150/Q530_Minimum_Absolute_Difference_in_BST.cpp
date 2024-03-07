#include <climits>
#include <cmath>
//Definition for a binary tree node.
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
    int getMinimumDifference(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 0;
        TreeNode *prev = nullptr;
        return min_diff(root, prev);
    }

    int min_diff(TreeNode* curr, TreeNode* &prev) {
        int diff = INT_MAX;
        if (curr->left) {
            int tmp_diff = min_diff(curr->left, prev);
            if (tmp_diff < diff) diff = tmp_diff;
        }
        if (prev) {
            int tmp_diff = std::abs(prev->val - curr->val);
            if (tmp_diff < diff) diff = tmp_diff;
        }
        prev = curr;
        if (curr->right) {
            int tmp_diff = min_diff(curr->right, prev);
            if (tmp_diff < diff) diff = tmp_diff;
        }
        return diff;
    }
};