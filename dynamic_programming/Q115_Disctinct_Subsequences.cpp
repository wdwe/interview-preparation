#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    int numDistinct(string s, string t) {
        vector<unsigned int> track(t.size(), 0), next_track(t.size(), 0);
        for (char c: s) {
            next_track[0] = track[0] + (t[0] == c ? 1: 0);
            for (std::size_t i = 1; i < t.size(); i++) {
                next_track[i] = track[i] + (t[i] == c ? track[i - 1]: 0);
            }
            std::swap(next_track, track);
        }
        return track[track.size() - 1];
    }
};