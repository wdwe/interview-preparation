#include <climits>
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
    bool isValidBST(TreeNode* root) {
        int max_val, min_val;
        return valid_subtree(root, max_val, min_val);
    }

    bool valid_subtree(TreeNode* node, int &max_val, int &min_val) {
        if (node) {
            int l_max = INT_MIN, l_min = INT_MAX, r_max = INT_MIN, r_min = INT_MAX;
            bool l_valid = valid_subtree(node->left, l_max, l_min);
            bool r_valid = valid_subtree(node->right, r_max, r_min);
            max_val = r_max > node->val? r_max: node->val;
            min_val = l_min < node->val? l_min: node->val;
            bool node_valid = true;
            if (node->left && l_max >= node->val) node_valid = false;
            if (node->right && r_min <= node->val) node_valid = false;
            return l_valid && r_valid && node_valid;
        }
        return true;
    }
};