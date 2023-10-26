#include <string>
#include <utility>
#include <algorithm>
#include <sstream>

typedef std::pair<int, std::string> pis;

/*
 *  I             1
    V             5
    X             10
    L             50
    C             100
    D             500
    M             1000
 *
 */
class Solution {
public:
    std::string intToRoman(int num) {
        std::vector<pis> mapping{
                {1, "I"},
                {5, "V"},
                {10, "X"},
                {50, "L"},
                {100, "C"},
                {500, "D"},
                {1000, "M"},
                {4, "IV"},
                {9, "IX"},
                {40, "XL"},
                {90, "XC"},
                {400, "CD"},
                {900, "CM"}
        };
        std::vector<std::string> romans;
        std::stringstream roman_stream;
        std::sort(mapping.begin(), mapping.end(), std::greater<pis>());
        for (pis &p: mapping) {
            if (p.first <= num) {
                int c = num / p.first;
                num -= p.first * c;
                for (int i = 0; i < c; ++i)
                    roman_stream << p.second;
            }
        }
        return roman_stream.str();
    }
};