#include <vector>
#include <algorithm>
#include <queue>
using std::queue;
using std::vector;

class Solution {
/*
 * use Kanh's algorithm
 */
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // build graph
        vector<vector<int>> graph(numCourses, vector<int>());
        for (auto &pre: prerequisites) {
            auto a = pre[0], b = pre[1];
            graph[b].push_back(a);
        }
        // kanh's algo
        vector<size_t> indegree (numCourses, 0);
        vector<int> res;
        queue<int> q;
        for (int u = 0; u < numCourses; ++u) {
            for (auto v: graph[u]) {
                ++indegree[v];
            }
        }
        for (int u = 0; u < numCourses; ++u) {
            if (indegree[u] == 0)
                q.push(u);
        }
        while (!q.empty()) {
            int u = q.front(); q.pop();
            res.push_back(u);
            for (int v: graph[u]) {
                if (--indegree[v] == 0)
                    q.push(v);
            }
        }
        if (res.size() != numCourses) return {};
        return res;
    }
/*
 * use DFS topological sort
 */
//public:
//    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//        // build graph
//        vector<vector<int>> graph(numCourses, vector<int>());
//        for (auto &pre: prerequisites) {
//            auto a = pre[0], b = pre[1];
//            graph[b].push_back(a);
//        }
//        vector<bool> vis(numCourses), vis_final(numCourses);
//        // topological sort
//        vector<int> res, order;
//        for (int u = 0; u < numCourses; ++u) {
//            if (vis_final[u]) continue;
//            if (!topo_dfs(u, order, graph, vis_final, vis)) return {};
//            std::copy(order.cbegin(), order.cend(), std::back_inserter(res));
//            order.clear();
//        }
//        std::reverse(res.begin(), res.end());
//        return res;
//    }
//private:
//    bool topo_dfs(int u, vector<int>& order, vector<vector<int>>& graph, vector<bool> &vis_final, vector<bool> &vis) {
//        if (vis[u]) return false;
//        if (vis_final[u]) return true;
//        vis_final[u] = true;
//        vis[u] = true;
//        for (int v: graph[u]) {
//            if (!topo_dfs(v, order, graph, vis_final, vis)) return false;
//        }
//        order.push_back(u);
//        vis[u] = false;
//        return true;
//    }
};