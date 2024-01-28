
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
    int kthSmallest(TreeNode* root, int k) {
        int rank = 1;
        TreeNode* node = in_order(root, rank, k);
        return node->val;
    }

    TreeNode* in_order(TreeNode* node, int &rank, int target) {
        if (!node) return nullptr;
        if (node->left) {
            TreeNode* ret = in_order(node->left, rank, target);
            if (ret) return ret;
        }
        if (rank == target) return node;
        ++rank;
        if (node->right) {
            TreeNode* ret = in_order(node->right, rank, target);
            if (ret) return ret;
        }
        return nullptr;
    }
};