#include <string>
#include <vector>

using std::string;
using std::vector;

class TrieNode {
public:
    bool word = false;
    vector<TrieNode*> children{26, nullptr};
};


class WordDictionary {
public:
    WordDictionary() {

    }

    void addWord(string word) {
        root = insert(root, word);
    }

    bool search(string word) {
        return search_string(root, word);
    }
private:
    TrieNode* root = nullptr;
    TrieNode* insert(TrieNode* node, const string &s, int c = 0) {
        if (!node) node = new TrieNode();
        if (c == s.size()) node->word = true;
        if (c < s.size())
            node->children[s[c] - 'a'] = insert(node->children[s[c] - 'a'], s, c + 1);
        return node;
    }

    bool search_string(TrieNode* node, const string &s, int c = 0) {
        if (!node) return false;
        if (c == s.size() - 1) {
            if (s[c] == '.') {
                for (auto &n: node->children) {
                    if (n && n->word) return true;
                }
                return false;
            }
            if (node->children[s[c] - 'a']) {
                return node->children[s[c] - 'a']->word;
            }
        }
        if (s[c] == '.') {
            for (auto &n: node->children) {
                if (search_string(n, s, c + 1)) return true;
            }
            return false;
        }
        return search_string(node->children[s[c] - 'a'], s, c + 1);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */