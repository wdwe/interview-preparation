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
#include <queue>
#include <climits>

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        // use the bfs to go through levels one by one
        std::queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        int level = 1, res_level = 0, max_sum = INT_MIN, curr_sum = 0;
        while (q.size() != 1) {
            TreeNode *node = q.front();
            q.pop();
            if (node) { // not nullptr
                curr_sum += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                if (q.front() == nullptr) q.push(nullptr);
            } else { // nullptr
                if (curr_sum > max_sum) {
                    res_level = level;
                    max_sum = curr_sum;
                }
                curr_sum = 0;
                level++;
            }
        }
        return res_level;
    }
};