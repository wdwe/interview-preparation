#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
#include <utility>

using std::vector;
using std::string;
using std::unordered_set;
using std::queue;
using std::pair;

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> gene_set(bank.cbegin(), bank.cend());

        vector<string> genes(gene_set.cbegin(), gene_set.cend());
        vector<vector<int>> graph(genes.size());

        for (int u = 0; u < genes.size(); ++u) {
            for (int v = u + 1; v < genes.size(); ++v) {
                string gene_u = genes[u], gene_v = genes[v];
                if (is_connected(gene_u, gene_v)) {
                    graph[u].push_back(v);
                    graph[v].push_back(u);
                }
            }
        }

        if (!gene_set.contains(endGene)) return -1;

        int end = std::find(genes.cbegin(), genes.cend(), endGene) - genes.cbegin();
        int start = -1;
        if (gene_set.contains(startGene)) start = std::find(genes.cbegin(), genes.cend(), startGene) - genes.cbegin();

        if (start == -1) {
            start = static_cast<int>(graph.size());
            graph.emplace_back();
            for (int u = 0; u < genes.size(); ++u) {
                string gene_u = genes[u];
                if (is_connected(gene_u, startGene)) graph[start].push_back(u);
            }
        }

        queue<pair<int, int>> q;
        vector<bool> vis(graph.size());

        q.emplace(start, 0);
        while (!q.empty()) {
            auto [u, step] = q.front(); q.pop();
            if (u == end) return step;
            if (vis[u]) continue;
            vis[u] = true;
            for (auto v: graph[u]) {
                if (vis[v]) continue;
                q.emplace(v, step + 1);
            }
        }
        return -1;
    }

private:
    static bool is_connected(string a, string b) {
        int change = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) {
                change++;
            }
        }
        return change == 1;
    }
};