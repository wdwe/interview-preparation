#include <string>
#include <utility>
#include <algorithm>
#include <sstream>

class Solution {
public:
    std::string reverseWords(std::string s) {
        std::vector<std::string> words;
        std::istringstream buffer(s);
        std::copy(std::istream_iterator<std::string>(buffer), std::istream_iterator<std::string>(), std::back_inserter(words));
//        std::reverse(words.begin(), words.end());
        std::ostringstream output;
        auto beg = words.crbegin(), end = words.crend();
        if (beg != end) {
            while (beg != end - 1)
                output << *beg++ << " ";
            output << *beg++;
        }
        return output.str();
    }
};