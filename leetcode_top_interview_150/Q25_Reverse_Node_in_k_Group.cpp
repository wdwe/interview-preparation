
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *start = new ListNode();
//        int pos = 0;
        ListNode *left_end = start, *tail = head->next, *curr = tail, *prev = head, *right_end = prev;
        start->next = head;
        while (true) {
            int pos = 1;
            while (tail != nullptr && pos < k) {
                ++pos;
                tail = tail->next;
            }
            if (tail == nullptr) break; // less than k element
            // reset tail
            tail = curr;
            pos = 1;
            right_end = prev;
            // curr's next needs to be set to null
            while (tail != nullptr && pos < k) {
                ++pos;
                ListNode* tmp = tail->next;
                tail->next = prev;
                prev = tail;
                tail = tmp;
            }
            curr = tail;
            left_end->next = prev;
            left_end = right_end;
            right_end->next = tail;
            prev = tail;
            tail = tail->next;
        }
        ListNode *res = start->next;
        delete start;
        return res;
    }

};