
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return nullptr;
        ListNode *curr = head;
        int n = 0;
        while (curr->next != nullptr) {
            curr = curr->next;
            ++n;
        }
        ++n;
        int shift = n - k % n;
        curr->next = head;
        curr = head;
        for (int c = 0; c < shift; ++c) curr = curr->next;
        ListNode *tail = curr;
        while (tail->next != curr) tail = tail->next;
        tail->next = nullptr;
        return curr;
    }
};