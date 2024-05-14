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

#include <algorithm>
class Solution {
public:
    int longestZigZag(TreeNode* root) {
        int max_length = 0;
        recurse(root->left, true, max_length);
        recurse(root->right, false, max_length);
        return max_length;
    }

    int recurse(TreeNode* node, bool is_left, int &max_length) {
        if (node) {
            int left = recurse(node->left, true, max_length);
            int right = recurse(node->right, false, max_length);
            int length = 1;
            if (is_left)
                length += right;
            else
                length += left;
            max_length = max(max_length, length);
            return length;
        }
        return 0;
    }

};