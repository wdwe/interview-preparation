#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using std::vector;
using std::pair;
using std::priority_queue;

typedef pair<int, int> p_ii;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<p_ii> projects;
        for (size_t i = 0; i < profits.size(); ++i)
            projects.emplace_back(capital[i], profits[i]);
        std::sort(projects.begin(), projects.end());

        priority_queue<int> q;
        size_t i = 0;
        while (i < projects.size() && k > 0) {
            if (projects[i].first <= w) {
                q.push(projects[i].second);
                ++i;
            } else if (!q.empty()){
                w += q.top();
                q.pop();
                --k;
            } else {
                break;
            }
        }
        while (k > 0 && !q.empty()) {
            w += q.top();
            q.pop();
            --k;
        }

        return w;
    }
};