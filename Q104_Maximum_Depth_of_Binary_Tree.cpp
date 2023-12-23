#include <algorithm>
#include <vector>
#include <utility>

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
//    static int maxDepth(TreeNode* root) {
//        if (root == nullptr) return 0;
//        int left_depth = root->left == nullptr ? 0 : maxDepth(root->left);
//        int right_depth = root->right == nullptr ? 0 : maxDepth(root->right);
//        return std::max(left_depth, right_depth) + 1;
//    }

    // with stack
    static int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int max_depth = 0;
        std::vector<std::pair<int, TreeNode*>> stack;
        stack.emplace_back(1, root);
        while (!stack.empty()) {
            auto p = stack.back();
            stack.pop_back();
            max_depth = std::max(max_depth, p.first);
            if (p.second->left != nullptr) stack.emplace_back(p.first + 1, p.second->left);
            if (p.second->right != nullptr) stack.emplace_back(p.first + 1, p.second->right);
        }
        return max_depth;
    }
};