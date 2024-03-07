#include <queue>
#include <functional>

using std::priority_queue;

class MedianFinder {
public:
    MedianFinder() {

    }

    void addNum(int num) {
        if (!min_pq.empty()) {
            if (num < min_pq.top()) {
                max_pq.emplace(num);
                if (max_pq.size() - min_pq.size() == 2){
                    min_pq.emplace(max_pq.top());
                    max_pq.pop();
                }
            } else {
                min_pq.emplace(num);
                if (min_pq.size() - max_pq.size() == 2) {
                    max_pq.emplace(min_pq.top());
                    min_pq.pop();
                }
            }
        } else {
            min_pq.emplace(num);
        }
    }

    double findMedian() {
        if ((min_pq.size() + max_pq.size()) & 1) {
            if (min_pq.size() > max_pq.size()) return min_pq.top();
            return max_pq.top();
        }
        return static_cast<double>(min_pq.top() + max_pq.top()) / 2;
    }

private:
    priority_queue<int> max_pq;
    priority_queue<int, std::vector<int>, std::greater<>> min_pq;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */