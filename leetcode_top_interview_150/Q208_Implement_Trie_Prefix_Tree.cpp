#include <string>
#include <vector>
#include <utility>

using namespace std;

class r_node {
public:
    vector<r_node*> children{26, nullptr};
    bool word = false;
};


class Trie {
public:
    Trie() {

    }

    ~Trie() {
        destruct(root);
    }

    void insert(string word) {
        insert(root, word);
    }

    bool search(string word) {
        r_node* node = search_string(root, word);
        if (node) return node->word;
        return false;
    }

    bool startsWith(string prefix) {
        r_node* node = search_string(root, prefix);
        return node;
    }
private:
    r_node root_node;
    r_node *root = &root_node;
    void insert(r_node* node, const string &s, int c = 0) {
        if (c == s.size()) return;
        r_node* &child = node->children[s[c] - 'a'];
        if (!child) child = new r_node();
        if (c == s.size() - 1) child->word = true;
        insert(child, s, c + 1);
    }

    r_node* search_string(r_node* node, const string& str, int c = 0) {
        r_node* child = node->children[str[c] - 'a'];
        if (child) {
            if (c == str.size() - 1) return child;
            return search_string(child, str, c + 1);
        } else {
            return nullptr;
        }
    }

    void destruct(r_node* node) {
        for (auto n: node->children) {
            if (n) destruct(n);
            delete n;
        }
    }

};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */