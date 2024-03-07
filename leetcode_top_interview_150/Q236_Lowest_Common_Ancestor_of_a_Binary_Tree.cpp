
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    static TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* lowest;
        bool node1_found, node2_found;
        isAncestor(lowest, root, p, q, node1_found, node2_found);
        return lowest;
    }

    static void isAncestor(TreeNode*& lowest, TreeNode* curr, TreeNode* node1, TreeNode* node2, bool& node1_found, bool& node2_found) {
        if (!curr) return;

        TreeNode* tmp_lowest = nullptr;
        bool tmp_1_found = false, tmp_2_found = false;

        isAncestor(tmp_lowest, curr->left, node1, node2, tmp_1_found, tmp_2_found);
        node1_found = tmp_1_found;
        node2_found = tmp_2_found;
        if (!tmp_lowest) {
            isAncestor(tmp_lowest, curr->right, node1, node2, tmp_1_found, tmp_2_found);
            node1_found = node1_found || tmp_1_found;
            node2_found = node2_found || tmp_2_found;
        }

        if (tmp_lowest) {
            lowest = tmp_lowest;
            return;
        }

        node1_found = node1_found || curr == node1;
        node2_found = node2_found || curr == node2;

        if (node1_found && node2_found)
            lowest = curr;

    }
//    alternate (more succinct) solution source: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/solutions/3649508/c-easy-method/?envType=study-plan-v2&envId=top-interview-150
// the insight here is that the lowestCommonAncestor is the only node whose l and r are
// not nullptr at the same time (see code)
// however, this code will produce false positive if the only one node p is present in the tree
//public:
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//        if(!root){
//            return NULL;
//        }
//        if(root==p || root==q)return root;
//        TreeNode* l,*r;
//        l = lowestCommonAncestor(root->left,p,q);
//        r= lowestCommonAncestor(root->right,p,q);
//        if(l && r)return root;
//        if(l)return l;
//        if(r) return r;
//        return NULL;
//    }
};