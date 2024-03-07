//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    static ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *start = new ListNode();
        start->next = head;
        ListNode *front = start, *back = start;
        for (int i = 0; i < n + 1; ++i) front = front->next;
        while(front != nullptr) {
            front = front->next;
            back = back->next;
        }
        ListNode *tmp = back->next;
        back->next = tmp->next;
        delete tmp;
        ListNode *res = start->next;
        delete start;
        return res;
    }
};