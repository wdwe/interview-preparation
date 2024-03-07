#include <vector>
#include <queue>

//Definition for a binary tree node.
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
    std::vector<double> averageOfLevels(TreeNode* root) {
        std::queue<TreeNode*> node_q;
        std::vector<double> res;
        long long total_value = 0;
        int num_node = 0;
        if (root) {
            node_q.push(root);
            node_q.push(nullptr); // use null ptr to indicate the end of one level
        }
        while (!node_q.empty()) {
            TreeNode *b = node_q.front();
            node_q.pop();
            if (b) {
                if (b->left) node_q.push(b->left);
                if (b->right) node_q.push(b->right);
                total_value += b->val;
                ++num_node;
            } else {
                double avg = static_cast<double>(total_value) / num_node;
                res.push_back(avg);
                total_value = 0;
                num_node = 0;
                if (!node_q.empty()) node_q.push(nullptr);
            }
        }
        return res;
    }
};