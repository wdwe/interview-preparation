#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int currGas = 0;
        int deficit = 0;
        int candidateLoc = 0;
        for (std::size_t i = 0; i < gas.size(); ++i) {
            currGas += gas[i] - cost[i];
            if (currGas < 0) {
                candidateLoc = i + 1;
                deficit += currGas;
                currGas = 0;
            }
        }
        if (candidateLoc < gas.size() && (currGas + deficit >= 0)) {
            return candidateLoc;
        }
        return -1;
    }
};