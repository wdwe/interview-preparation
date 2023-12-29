#include <queue>
#include <utility>
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        Node *next = root;
        while (next) {
            Node *last = nullptr;
            Node* curr = next;
            next = nullptr;
            while (curr) {
                if (curr->left) {
                    if (!last) {
                        last = curr->left;
                        next = curr->left;
                    }
                    else {
                        last->next = curr->left;
                        last = last->next;
                    }
                }

                if (curr->right) {
                    if (!last) {
                        last = curr->right;
                        next = curr->right;
                    }
                    else {
                        last->next = curr->right;
                        last = last->next;
                    }
                }
                curr = curr->next;
            }
        }
        return root;
    }

    /*
     * bfs using queue
     */
//    Node* connect(Node* root) {
//        std::queue<std::pair<Node*, int>> q;
//        if (root != nullptr)
//            q.emplace(root, 0);
//
//        while (!q.empty()) {
//            auto [node, rank] = q.front(); q.pop();
//            if (node->left != nullptr)
//                q.emplace(node->left, rank + 1);
//            if (node->right != nullptr)
//                q.emplace(node->right, rank + 1);
//            if (!q.empty() && q.front().second == rank)
//                node->next = q.front().first;
//        }
//        return root;
//    }
};