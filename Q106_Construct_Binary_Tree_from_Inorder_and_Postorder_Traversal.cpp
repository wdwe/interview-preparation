#include <vector>
#include <unordered_map>
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
    static TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
        std::unordered_map<int, std::size_t> order;
        for (std::size_t i = 0; i < inorder.size(); ++i) order[inorder[i]] = i;
        std::size_t idx = postorder.size() - 1;
        auto root = build(idx, 0, inorder.size(), order, postorder);
        return root;
    }

    static TreeNode* build(std::size_t& idx, std::size_t l, std::size_t r, std::unordered_map<int, std::size_t> &order,
                           std::vector<int>& postorder) {
        if (l == r) return nullptr;
        int root_val = postorder[idx--];
        std::size_t loc = order[root_val];
        auto *root = new TreeNode(root_val);
        root->right = build(idx, loc+1, r, order, postorder);
        root->left = build(idx, l, loc, order, postorder);
        return root;
    }
};