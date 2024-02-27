#include <queue>
#include <functional>

using std::priority_queue;
using std::vector;
using std::pair;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution {
    typedef pair<int, ListNode*> item_type;
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;

        priority_queue<item_type, vector<item_type>, std::greater<>> pq;
        for (auto *node: lists)
            if (node)
                pq.push({node->val, node});
        if (pq.empty())
            return nullptr;

        auto [val, node] = pq.top();
        pq.pop();
        ListNode *head = node, *tail = node;

        if (node->next)
            pq.push({node->next->val, node->next});

        while (!pq.empty()) {
            auto [val, node] = pq.top();
            pq.pop();
            tail->next = node;
            tail = tail->next;
            if (node->next)
                pq.push({node->next->val, node->next});
        }
        return head;
    }
};