
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* start = new ListNode();
        start->next = head;
        ListNode* left = start, *right = start;
        while (right->next != nullptr) {
            if (right->next->val < x) {
                if (left == right) {
                    right = right->next;
                    left = left->next;
                } else {
                    ListNode *tmp = right->next;
                    right->next = right->next->next;
                    tmp->next = left->next;
                    left->next = tmp;
                    left = left->next;
                }
            } else
                right = right->next;
        }
        ListNode* res = start->next;
        delete start;
        return res;
    }
};