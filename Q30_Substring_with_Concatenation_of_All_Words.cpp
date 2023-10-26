#include <vector>
#include <unordered_set>
#include <string>

class Solution {
public:
    static std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
        int wc = (int)words.size(), wl = (int)words.at(0).length();
        std::unordered_map<std::string, int> avail_words;
        for (auto w: words) ++avail_words[w];
        std::vector<int> res;
        for (int offset = 0; offset < wl; ++offset) {
            int l, r, curr_num = 0;
            l = r = offset;
            std::unordered_map<std::string, int> words_seen;
            while (r < s.length() - wl + 1) {
                std::string sub = s.substr(r, wl);
                r += wl;
                if (!avail_words.contains(sub)) {
                    words_seen.clear();
                    curr_num = 0;
                    l = r;
                    continue;
                }

                ++words_seen[sub];
                ++curr_num;
                auto iter = words_seen.find(sub);
                int avail_num = avail_words.find(sub)->second;
                if (iter->second <= avail_num) {
                    if (curr_num == wc) {
                        res.push_back(l);
                        std::string first = s.substr(l, wl);
                        --words_seen.find(first)->second;
                        --curr_num;
                        l += wl;
                    }
                    continue;
                }

                // if words_seen[sub] == avail_num + 1
                while (true) {
                    std::string first = s.substr(l, wl);
                    --curr_num;
                    l += wl;
                    --words_seen.find(first)->second;
                    if (first == sub) break;
                }
            }
        }
        return res;
    }
};