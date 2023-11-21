
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // reach left, record left end
        // reverse the segment
        ListNode *left_end = nullptr;
        ListNode *tail = head;
        int pos = 1;
        if (left != 1) {
            while (pos != left - 1) {
                tail = tail->next;
                ++pos;
            }
            left_end = tail;
        }
        ListNode *left_node = nullptr;
        if (left_end == nullptr) {
            left_node = head;
        } else {
            left_node = tail->next;
            tail = tail->next;
            ++pos;
        }
        ListNode *prev = left_node;
        if (pos <= right) {
            tail = tail->next;
            ++pos;
            while (pos <= right) {
                ListNode *tmp = tail->next;
                tail->next = prev;
                prev = tail;
                tail = tmp;
                ++pos;
            }
        }
        if (left_end != nullptr) left_end->next = prev;
        else head = prev;
        left_node->next = tail;
        return head;
    }
};