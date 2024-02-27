// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


#include <vector>
using std::vector;

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build_bst(0, nums.size(), nums);
    }

    TreeNode* build_bst(int i, int j, vector<int>& nums) {
        if (i == j) return nullptr;
        int mid = (i + j) / 2;
        auto node = new TreeNode(nums[mid]);
        node->left = build_bst(i, mid, nums);
        node->right = build_bst(mid + 1, j, nums);
        return node;
    }
};