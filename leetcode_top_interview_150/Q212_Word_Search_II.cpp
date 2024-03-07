#include <string>
#include <vector>
#include <unordered_set>

using std::string;
using std::vector;
using std::unordered_set;

class TrieNode {
public:
    bool is_word = false;
    vector<TrieNode*> next{26, nullptr};
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        unordered_set<string> found;
        for (auto w: words) {
            insert(w);
        }
        if (!root) return {};
        vector<vector<bool>> used(board.size(), vector<bool>(board[0].size(), false));
        for (int y = 0; y < board.size(); ++y) {
            for (int x = 0; x < board[0].size(); ++x) {
                string prefix;
                check(board, y, x, prefix, root, found, used);
            }
        }
        vector<string> found_vec(found.cbegin(), found.cend());
        cleanup(root);
        root = nullptr;
        return found_vec;
    }
private:
    TrieNode* root = nullptr;
    void insert(const string& s) {
        if (!root) root = new TrieNode();
        TrieNode *node = root;
        for (auto ch: s) {
            if (!node->next[ch - 'a']) {
                node->next[ch - 'a'] = new TrieNode;
            }
            node = node->next[ch - 'a'];
        }
        node->is_word = true;
    }

    void check(vector<vector<char>>& board, int y, int x, string& prefix, TrieNode* node, unordered_set<string> &found, vector<vector<bool>> &used) {
        if (used[y][x]) return;
        used[y][x] = true;
        char ch = board[y][x];
        prefix.push_back(ch);
        auto next = node->next[ch - 'a'];
        if (next) {
            if (next->is_word) found.insert(prefix);
            if (y - 1 >= 0) check(board, y - 1, x, prefix, next, found, used);
            if (y + 1 < board.size()) check(board, y + 1, x, prefix, next, found, used);
            if (x - 1 >= 0) check(board, y, x - 1, prefix, next, found, used);
            if (x + 1 < board[0].size()) check(board, y, x + 1, prefix, next, found, used);
        }

        used[y][x] = false;
        prefix.pop_back();
    }

    void cleanup(TrieNode* node) {
        if (node) {
            for (auto n: node->next) {
                if (n) cleanup(n);
            }
        }
        delete node;
    }
};