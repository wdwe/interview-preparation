#include <vector>
#include <utility>
#include <cmath>

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
    // Morris traversal
    int sumNumbers(TreeNode* root) {
        int sum = 0, partial = 0;
        while (root) {
            if (root->left) {
                TreeNode* curr = root->left;
                int steps = 1;
                while (curr->right && curr->right != root) {
                    curr = curr->right;
                    ++steps;
                }

                if (!curr->right) {
                    partial = partial * 10 + root->val;
                    curr->right = root;
                    root = root->left;
                } else {
                    curr->right = nullptr;
                    if (!curr->left) // when "loop" is detected, the curr not be a leaf, so we need to check leaf condition
                        sum += partial;
                    partial = static_cast<double>(partial) / std::pow(10, steps);
                    root = root->right; // root may be null here too
                }

            } else {
                partial = partial * 10 + root->val;
                root = root->right;
                if (!root) sum += partial; // adding when exiting from the right most leaf
            }
        }
        return sum;
    }


//    int sumNumbers(TreeNode* root) {
//        if (!root) return 0;
//        std::vector<std::pair<TreeNode*, int>> stack;
//        int result = 0, partial = 0;
//        TreeNode* node = root;
//        while (true) {
//            partial = partial * 10 + node->val;
//            if (!node->left && !node->right) {
//                result += partial;
//                if (!stack.empty()) {
//                    node = stack.back().first;
//                    partial = stack.back().second;
//                    stack.pop_back();
//                    continue;
//                }
//                else
//                    break;
//            }
//            if (node->left && node->right) {
//                stack.emplace_back(node->right, partial);
//                node = node->left;
//            } else
//                node = node->left? node->left: node->right;
//        }
//        return result;
//    }
};