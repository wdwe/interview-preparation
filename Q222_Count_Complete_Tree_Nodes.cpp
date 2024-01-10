#include <vector>
#include <utility>
#include <algorithm>

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
    int countNodes(TreeNode* root) {
        // checking left and right
        std::vector<std::pair<TreeNode*, int>> nodes;
        int h = 0, leaves = 0;
        bool incomplete = false;
        if (root) {
            nodes.emplace_back(root, 1);
            h = 1;
        }
        while(!nodes.empty()) {
            auto [node, h_] = nodes.back();
            nodes.pop_back();
            if (node->right && node->left) {
                nodes.emplace_back(node->right, h_ + 1);
                nodes.emplace_back(node->left, h_ + 1);
                h = std::max(h, h_ + 1);
            } else if (!node->left && !node->right) {
                if (h_ < h) { // current leaf has lower height
                    incomplete = true;
                    break;
                }
                ++leaves;
            } else { // current node contains only one leaf
                h = std::max(h, h_ + 1);
                ++leaves;
                incomplete = true;
                break;
            }
        }
        if (incomplete)
            return (1 << (h - 1)) - 1 + leaves;
        return (1 << h) - 1;
    }
};