
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;
        ListNode *start = new ListNode();
        start->next = head;
        ListNode *curr = start, *front = head;
        int val = front->val;
        bool dup = false;
        while (front != nullptr) {
            front = front->next;
            while (front != nullptr && front->val == val) {
                dup = true;
                front = front->next;
            }
            // front points to non-repeat pos
            if (dup) {
                // delete nodes
                ListNode *tmp = curr->next;
                while (tmp != front) {
                    curr->next = tmp->next;
                    delete tmp;
                    tmp = curr->next;
                }
//                curr->next = front;
                dup = false;
            } else {
                curr = curr->next;
            }
            if (front != nullptr) {
                val = front->val;
            }
        }
        ListNode *res = start->next;
        delete start;
        return res;
    }
};