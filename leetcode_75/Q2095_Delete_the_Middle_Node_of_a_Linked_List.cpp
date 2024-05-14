/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* start = new ListNode(0, head);
        ListNode *curr = start;
        std::size_t n = 0;
        while (curr->next) {
            n++;
            curr = curr->next;
        }
        curr = start;
        std::size_t pos = n / 2;
        while (pos > 0) {
            pos--;
            curr = curr->next;
        }
        if (curr->next)
            curr->next = curr->next->next;
        ListNode *res = start->next;
        delete start;
        return res;
    }
};