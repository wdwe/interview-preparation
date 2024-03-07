#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <utility>

using std::vector;
using std::queue;
using std::string;
using std::unordered_set;
using std::unordered_map;
using std::pair;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> seen;
        unordered_map<string, vector<string>> graph;
        for (size_t i = 0; i < wordList.size(); ++i) {
            for (size_t j = i + 1; j < wordList.size(); ++j) {
                if (diff_by_one(wordList[i], wordList[j])) {
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        if (!graph.contains(beginWord)) {
            for (const auto & s : wordList) {
                if (diff_by_one(s, beginWord)) {
                    graph[beginWord].push_back(s);
                }
            }
        }

        queue<pair<string, int>> q;
        q.emplace(beginWord, 2);
        while (!q.empty()) {
//            auto [word, step] = q.front(); q.pop();
            string word = q.front().first;
            int step = q.front().second;
            q.pop();
            if (word == endWord)
                return step;
            if (seen.contains(word)) continue;
            seen.insert(word);
            for (const string& w: graph[word]) {
                q.emplace(w, step + 1);
            }
        }
        return 0;
    }

private:
    static bool diff_by_one(string a, string b) {
        size_t diff = 0;
        for (size_t i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) ++diff;
        }
        return diff == 1;
    }
};