/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // always pass the parent and pos down
        TreeNode helper_node = TreeNode(0, root, nullptr);
        TreeNode *helper = &helper_node;
        search(helper->left, helper, true, key);
        return helper->left;
    }

    void search(TreeNode *node, TreeNode *parent, bool is_left, int key) {
        if (node) {
            if (node->val == key) {
                TreeNode *suc;
                if (node->left) {
                    suc = node->left;
                    if (node->right) {
                        TreeNode *tmp = suc->right;
                        suc->right = node->right;
                        TreeNode *n = node->right;
                        while (n->left) n = n->left;
                        n->left = tmp;
                    }
                }
                else suc = node->right;
                if (is_left) {
                    parent->left = suc;
                } else {
                    parent->right = suc;
                }
            } else if (key > node->val) {
                search(node->right, node, false, key);
            } else {
                search(node->left, node, true, key);
            }
        }
        // if node is nullptr
        return;
    }
};