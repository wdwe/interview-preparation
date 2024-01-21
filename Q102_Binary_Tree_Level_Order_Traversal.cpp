#include <vector>
#include <queue>


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
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::queue<TreeNode*> q;
        std::vector<std::vector<int>> res;
        std::vector<int> level;
        if (root) {
            q.push(root);
            q.push(nullptr);
        }
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (node) {
                level.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            } else {
                if (!q.empty()) q.push(nullptr);
                res.push_back(level);
                level.clear();
            }
        }
        return res;
    }
};