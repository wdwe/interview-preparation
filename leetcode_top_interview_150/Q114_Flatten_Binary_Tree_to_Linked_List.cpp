
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
    void flatten(TreeNode* root) {
        TreeNode *tail = nullptr;
        attach(root, tail);
    }

    void attach(TreeNode* node, TreeNode* &tail) {
        if (!node) return;
        TreeNode* tmp_left = node->left, *tmp_right = node->right;
        node->left = nullptr;
        node->right = nullptr;
        if (tail) {
            tail->right = node;
            tail = tail->right;
        }
        else {
            tail = node;
        }
        attach(tmp_left, tail);
        attach(tmp_right, tail);
    }
};