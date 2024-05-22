from typing import List


class TrieNode:
    def __init__(self):
        self.word = False
        self.nodes = [None] * 26


class Solution:
    def suggestedProducts(
        self, products: List[str], searchWord: str
    ) -> List[List[str]]:
        self._build_trie(products)
        res = []
        self._get_suggestion(self.trie, searchWord, idx=0, prefix=[], res=res)
        return res

    def _build_trie(self, words):
        self.trie = None
        for word in words:
            self.trie = self._add_word(self.trie, word, idx=0)

    def _add_word(self, trie_node, word, idx):
        if trie_node is None:
            trie_node = TrieNode()
        if idx == len(word):
            trie_node.word = True
        else:
            key = ord(word[idx]) - ord("a")
            trie_node.nodes[key] = self._add_word(trie_node.nodes[key], word, idx + 1)
        return trie_node

    def _get_suggestion(self, node, word, idx, prefix, res):
        if node is None:
            res.extend([[] for _ in range(len(word) - idx)])
            return
        if idx == len(word):
            return
        key = ord(word[idx]) - ord("a")
        _res = []
        prefix.append(word[idx])
        self._traverse(node.nodes[key], prefix, _res)
        res.append(_res)
        self._get_suggestion(node.nodes[key], word, idx + 1, prefix, res)

    def _traverse(self, node, prefix, res):
        if len(res) == 3:
            return
        if node is not None:
            if node.word:
                res.append("".join(prefix))
            for ch, _node in enumerate(node.nodes):
                prefix.append(chr(ch + ord("a")))
                self._traverse(_node, prefix, res)
                prefix.pop()
