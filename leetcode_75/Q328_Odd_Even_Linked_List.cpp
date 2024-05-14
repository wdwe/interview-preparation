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
    ListNode* oddEvenList(ListNode* head) {
        ListNode even_node, odd_node;
        ListNode *even_start = &even_node, *odd_start = &odd_node;
        even_start->next = head;
        ListNode *even_curr = even_start, *odd_curr = odd_start;
        while (even_curr && even_curr->next) {
            odd_curr->next = even_curr->next;
            odd_curr = odd_curr->next;
            even_curr->next = odd_curr->next;
            odd_curr->next = nullptr;
            even_curr = even_curr->next;
        }
        odd_curr->next = even_start->next;
        return odd_start->next;
    }
};