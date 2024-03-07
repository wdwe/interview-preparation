#include <string>
#include <vector>
#include <algorithm>
#include <utility>

typedef std::vector<std::string> vs;
typedef std::vector<vs> vvs;
typedef std::pair<std::string, int> psi;

class Solution {
public:
    static vvs groupAnagrams(vs& strs) {
        std::vector<psi> orders;
        for (int i = 0; i < strs.size(); ++i) {
            orders.emplace_back(strs[i], i);
            std::sort(orders.back().first.begin(), orders.back().first.end());
        }
        auto comp = [] (const psi& p1, const psi& p2) {return p1.first < p2.first;};
        std::sort(orders.begin(), orders.end(), comp);
        vvs res;
        res.emplace_back();
        res.back().push_back(strs[orders[0].second]);
        for (int i = 1; i < orders.size(); ++i) {
            if (orders[i].first != orders[i - 1].first) {
                res.emplace_back();
            }
            res.back().push_back(strs[orders[i].second]);
        }
        return res;
    }
};

int main() {
    vs strs{"eat","tea","tan","ate","nat","bat"};
    Solution::groupAnagrams(strs);
}