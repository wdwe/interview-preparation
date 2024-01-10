#include <vector>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        parents.push_back(root);
        while(parents.back()->left) {
            parents.push_back(parents.back()->left);
        }
    }

    int next() {
        int val = parents.back()->val;
        TreeNode* next_ptr = parents.back()->right;
        parents.pop_back();
        while (next_ptr) {
            parents.push_back(next_ptr);
            next_ptr = next_ptr->left;
        }
        return val;
    }

    bool hasNext() {
        return !parents.empty();
    }
private:
    typedef std::vector<TreeNode*> stack;
    stack parents;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */