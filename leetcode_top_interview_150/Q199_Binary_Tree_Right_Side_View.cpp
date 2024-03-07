#include <vector>
#include <queue>
#include <utility>

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
    std::vector<int> rightSideView(TreeNode* root) {
        std::queue<std::pair<TreeNode*, int>> levels;
        std::vector<int> res;
        if (root) levels.emplace(root, 0);
        while(!levels.empty()) {
            auto [node, level_no] = levels.front();
            if (node->left) levels.emplace(node->left, level_no + 1);
            if (node->right) levels.emplace(node->right, level_no + 1);
            levels.pop();
            if (levels.empty() || levels.front().second > level_no)
                res.push_back(node->val);
        }

        return res;
    }
};
