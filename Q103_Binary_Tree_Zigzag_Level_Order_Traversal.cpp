#include <vector>
#include <queue>
#include <algorithm>
#include <iterator>

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
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::vector<std::vector<int>> res;
        std::queue<TreeNode*> q;
        std::vector<int> level;
        bool flip = false;
        if (root) {
            q.push(root);
            q.push(nullptr);
        }
        while (!q.empty()) {
            auto node = q.front(); q.pop();
            if (node) {
                level.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            } else {
                if (!q.empty()) q.push(nullptr);
                res.emplace_back();
                if (flip)
                    std::copy(level.crbegin(), level.crend(), std::back_inserter(res.back()));
                else
                    std::copy(level.cbegin(), level.cend(), std::back_inserter(res.back()));
                flip = !flip;
                level.clear();
            }
        }
        return res;
    }
};