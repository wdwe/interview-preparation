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
#include <unordered_map>

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        std::unordered_map<long long, int> path_sum;
        path_sum[0] = 1;
        int n = 0;
        count(path_sum, root, n, targetSum, 0);
        return n;
    }
    void count(std::unordered_map<long long, int> &path_sum, TreeNode *node, int &n, int target, long long prefix) {
        if (node) {
            long long curr = prefix + node->val;
            long long diff = curr - target;
            if (path_sum.contains(diff))
                n += path_sum[diff];
            path_sum[curr]++;
            count(path_sum, node->left, n, target, curr);
            count(path_sum, node->right, n, target, curr);
            if (--path_sum[curr] == 0)
                path_sum.erase(curr);
        }
    }
};