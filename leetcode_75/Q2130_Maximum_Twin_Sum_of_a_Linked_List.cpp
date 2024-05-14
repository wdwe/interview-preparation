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
#include <climits>
#include <algorithm>

class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode start_node(0, head);
        ListNode *start = &start_node;
        ListNode *slow = start, *fast = start;
        while (fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *next_node = nullptr, *curr = slow->next;
        while (curr) {
            ListNode *tmp = curr->next;
            curr->next = next_node;
            next_node = curr;
            curr = tmp;
        }
        ListNode *curr_2 = start->next, *rev_first = next_node;
        curr = next_node;
        int res = INT_MIN;
        while (curr) {
            res = std::max(res, curr->val + curr_2->val);
            curr = curr->next;
            curr_2 = curr_2->next;
        }
        // reverse back
        next_node = nullptr;
        curr = rev_first;
        while (curr) {
            ListNode *tmp = curr->next;
            curr->next = next_node;
            next_node = curr;
            curr = tmp;
        }
        slow->next = next_node;
        return res;
    }
};