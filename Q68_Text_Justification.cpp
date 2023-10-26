#include <vector>
#include <string>


class Solution {
public:
    std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth) {
        int n = static_cast<int>(words.size()), start = 0, end = 0, len = 0;
        std::vector<std::string> output;
        while (end < n) {
//            std::ostringstream buffer;
            std::string str;
            if (len + words.at(end).length() > maxWidth) {
                // compute avg spaces
                int num_words = end - start;
                if (num_words > 1) {
                    int avg_add_space = (maxWidth - len + 1) / (num_words - 1);
                    int remainder = (maxWidth - len + 1) % (num_words - 1);
                    for (int i = start; i < end; ++i) {
                        str += words.at(i) ;
                        if (i != end - 1) {
                            str += " " + std::string(avg_add_space, ' ');
                            if (i < start + remainder) str += " ";
                        }
                    }
                }
                else
                    str += words.at(start) + std::string(maxWidth - len + 1, ' ');
                output.push_back(str);
                start = end;
                len = 0;
            }
            else {
                len += (int) words.at(end).length() + 1;
                ++end;
            }
        }
        std::string str;
        for (int i = start; i < end; ++i) {
            str += words.at(i);
            if (i != end - 1) str += " ";
            else str += std::string(maxWidth - len + 1, ' ');
        }
        output.push_back(str);
        return output;
    }
};