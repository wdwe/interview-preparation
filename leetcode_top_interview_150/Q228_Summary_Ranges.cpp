#include <string>
#include <vector>

class Solution {
public:
    static std::vector<std::string> summaryRanges(std::vector<int>& nums) {
        std::vector<std::string> res;
        std::string s;
        if (nums.empty()) return res;

        int past_num = nums[0];
        s += std::to_string(past_num);
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != past_num + 1) {
                if (std::stoi(s) != past_num) {
                    s += "->";
                    s += std::to_string(past_num);
                }
                res.push_back(s);
                past_num = nums[i];
                s = std::to_string(past_num);
            }
            past_num = nums[i];
        }
        if (std::stoi(s) != past_num) {
            s += "->";
            s += std::to_string(past_num);
        }
        res.push_back(s);
        return res;
    }
};