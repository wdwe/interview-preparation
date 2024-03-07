#include <vector>
#include <unordered_set>
using std::vector;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        for (auto &prerequisite: prerequisites) {
            int a = prerequisite[0], b = prerequisite[1];
            graph[b].push_back(a);
        }
        vector<bool> vis(numCourses, false), vis_final(numCourses, false);
        for (int u = 0; u < numCourses; ++u) {
            if (!vis_final[u])
                if (!dfs(u, graph, vis, vis_final))
                    return false;
        }
        return true;
    }

private:
    bool dfs(int u, vector<vector<int>>& graph, vector<bool>& vis, vector<bool>& vis_final) {
        if (vis[u]) return false;
        if (vis_final[u]) return true;
        vis[u] = true;
        vis_final[u] = true;
        for (int v: graph[u])
            if (!dfs(v, graph, vis, vis_final))
                return false;
        vis[u] = false;
        return true;
    }
};