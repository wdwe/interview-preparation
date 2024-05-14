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
#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int goodNodes(TreeNode* root) {
        int n = 0;
        count(INT_MIN, n, root);
        return n;
    }

    void count(int highest, int &n, TreeNode *node) {
        if (node) {
            if (node->val >= highest)
                n++;
            count(std::max(highest, node->val), n, node->left);
            count(std::max(highest, node->val), n, node->right);
        }
    }
};