#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
#include <queue>

using std::vector;
using std::string;
using std::unordered_map;
using std::pair;

class Solution {
public:
    typedef std::unordered_map<string, vector<pair<string, double>>> graph_type;
    typedef std::unordered_map<string, std::unordered_map<string, double>> sp_type;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // build graph
        graph_type graph;
        for (std::size_t i = 0; i < equations.size(); ++i) {
            auto u = equations[i][0];
            auto v = equations[i][1];
            auto w = values[i];
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, 1 / w);
        }
        sp_type apsp;
        for (auto &[k, tmp]: graph) {
            std::queue<pair<string, double>> q;
            if (!apsp.contains(k)) apsp[k] = std::unordered_map<string, double>();
            auto &sp = apsp[k];
            q.emplace(k, 1);
            while (!q.empty()) {
                auto node = q.front(); q.pop();
                auto [u, val] = node;
                sp[u] = val;
                for (auto [v, w]: graph[u]) {
                    if (!sp.contains(v)) {
                        q.emplace(v, val * w);
                    }
                }
            }
        }

        vector<double> res;
        for (auto query: queries) {
            auto a = query[0], b = query[1];
            if (apsp.contains(a) && apsp[a].contains(b))
                res.push_back(apsp[a][b]);
            else
                res.push_back(-1);
        }
        return res;
    }
};