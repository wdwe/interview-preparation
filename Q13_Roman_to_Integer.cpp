#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        auto iter = s.cbegin();
        int num = 0;
        while (iter != s.cend()) {
            auto nextIter = iter + 1;
            switch (*iter) {
                case 'I':
                    num += 1;
                    if (nextIter != s.cend()) {
                        if (*nextIter == 'V') {
                            num += 3;
                            ++iter;
                        } else if (*nextIter == 'X') {
                            num += 8;
                            ++iter;
                        }
                    }
                    break;
                case 'V':
                    num += 5;
                    break;
                case 'X':
                    num += 10;
                    if (nextIter != s.cend()) {
                        if (*nextIter == 'L') {
                            num += 30;
                            ++iter;
                        } else if (*nextIter == 'C') {
                            num += 80;
                            ++iter;
                        }
                    }
                    break;
                case 'L':
                    num += 50;
                    break;
                case 'C':
                    num += 100;
                    if (nextIter != s.cend()) {
                        if (*nextIter == 'D') {
                            num += 300;
                            ++iter;
                        } else if (*nextIter == 'M') {
                            num += 800;
                            ++iter;
                        }
                    }
                    break;
                case 'D':
                    num += 500;
                    break;
                case 'M':
                    num += 1000;
                    break;
            }
            ++iter;
        }
        return num;
    }
};