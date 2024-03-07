#include <queue>
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
    static bool isSymmetric(TreeNode* root) {
        return isSym(root->left, root->right);
    }

    static bool isSym(TreeNode* left, TreeNode* right) {
        if (left == nullptr || right == nullptr) {
            if (left == nullptr && right == nullptr) return true;
            else return false;
        } else {
            return left->val == right->val &&
                   isSym(left->left, right->right) &&
                   isSym(left->right, right->left);
        }
    }

//    static bool isSymmetric(TreeNode* root) {
//        if (root == nullptr) return true;
//        std::queue<TreeNode*> left, right;
//        left.push(root->left);
//        right.push(root->right);
//        while(!left.empty() && !right.empty()) {
//            auto left_node = left.front(); left.pop();
//            auto right_node = right.front(); right.pop();
//            if (left_node == nullptr || right_node == nullptr) {
//                if (left_node != nullptr || right_node != nullptr)
//                    return false;
//            } else {
//                if (left_node->val != right_node->val) return false;
//                left.push(left_node->left);
//                left.push(left_node->right);
//                right.push(right_node->right);
//                right.push(right_node->left);
//            }
//        }
//        if (!left.empty() || !right.empty()) return false;
//        return true;
//    }
};