#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        unsigned int candies = 1, total = 0;
        int start = 0, checkPoint = 0;
        bool checkPointSet = false;
        while (start < ratings.size()) {
            int currRating = ratings[start];
            int leftRating = (start - 1 >= 0 ? ratings[start - 1] : INT_MAX);
            int rightRating = (start + 1 < ratings.size() ? ratings[start + 1] : INT_MAX);
            if (currRating > leftRating && currRating <= rightRating ||
                currRating >= leftRating && currRating < rightRating) {
                if (start == ratings.size() - 1 && currRating <= leftRating)
                    total += 1;
                else if (currRating > leftRating)
                    total += ++candies;
                else
                    total += candies;
            }
            if (!checkPointSet && (currRating > rightRating)) {
                checkPoint = start;
                checkPointSet = true;
            }
            if (currRating < leftRating && currRating < rightRating ||
                currRating == leftRating && currRating == rightRating) { // backward pass
                candies = 1;
                total += candies;
                for (int i = start - 1; i >= checkPoint; --i) {
                    if (ratings[i] > ratings[i + 1])
                        total += ++candies;
                    else
                        total += candies;
                }
                checkPoint = start + 1;
                candies = 1;
                checkPointSet = false;
            }
            ++start;
        }
        return total;
    }
};
