#include <vector>
#include <unordered_set>
#include <unordered_map>

using std::vector;
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    typedef std::unordered_map<Node*, Node*> node_map;

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        node_map mapping;
        auto new_node = new Node(node->val);

        dfs(node, new_node, mapping);
        return new_node;
    }

private:
    void dfs(Node* old_node, Node* new_node, node_map& mapping) {
        if (!old_node || mapping.contains(old_node)) return;
        mapping[old_node] = new_node;
        for (auto v: old_node->neighbors) {
            Node *u;
            if (mapping.contains(v)) {
                u = mapping[v];
            } else {
                u = new Node(v->val);
            }
            new_node->neighbors.push_back(u);
            dfs(v, u, mapping);
        }
    }
};