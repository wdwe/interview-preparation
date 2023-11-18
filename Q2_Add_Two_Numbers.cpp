
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* prev = nullptr, *start = nullptr;
        int c = 0;
        while (l1 != nullptr && l2 != nullptr) {
            int sum = l1->val + l2->val + c;
            c = sum / 10;
            if (prev == nullptr) {
                prev = new ListNode(sum % 10);
                start = prev;
            } else {
                prev->next = new ListNode(sum % 10);
                prev = prev->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode *remain = l1 == nullptr ? l2: l1;
        while (remain != nullptr) {
            int val = remain->val + c;
            c = val / 10;
            prev->next = new ListNode(val % 10);
            prev = prev->next;
            remain = remain->next;
        }
        if (c > 0) prev->next = new ListNode(c);
        return start;
    }
};