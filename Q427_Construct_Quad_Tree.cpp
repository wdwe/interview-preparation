#include <vector>
#include <tuple>

using std::vector;
using std::tuple;


// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
    typedef tuple<size_t, size_t, size_t, size_t> area_type;
    Node* construct(vector<vector<int>>& grid) {
        return quad_tree(grid, {0, 0, grid.size(), grid.size()});
    }

    Node* quad_tree(vector<vector<int>> &grid, area_type area) {
        auto [y1, x1, y2, x2] = area;
        if (x2 == x1 + 1)
            return new Node(grid[y1][x1] == 1, true);
        int xc = (x1 + x2) / 2, yc = (y1 + y2) / 2;

        Node *top_left = quad_tree(grid, {y1, x1, yc, xc});
        Node *top_right = quad_tree(grid, {y1, xc, yc, x2});
        Node *bot_left = quad_tree(grid, {yc, x1, y2, xc});
        Node *bot_right = quad_tree(grid, {yc, xc, y2, x2});
        if (top_left->isLeaf && top_right->isLeaf && bot_left->isLeaf && bot_right->isLeaf &&
            top_left->val == top_right->val && top_right->val == bot_left->val && bot_left->val == bot_right->val) {
            auto node = new Node(top_left->val, true);
            delete top_left;
            delete top_right;
            delete bot_left;
            delete bot_right;
            return node;
        }
        return new Node(true, false, top_left, top_right, bot_left, bot_right);
    }
};