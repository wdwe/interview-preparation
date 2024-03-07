
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
        ListNode *start = new ListNode(), *tail = start;
        int c = 0;
        while (l1 != nullptr || l2 != nullptr || c > 0) {
            int num1 = 0, num2 = 0;
            if (l1 != nullptr) {
                num1 = l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                num2 = l2->val;
                l2 = l2->next;
            }
            int val = num1 + num2 + c;
            c = val / 10;
            tail->next = new ListNode(val % 10);
            tail = tail->next;
        }
        ListNode *res = start->next;
        delete start;
        return res;
    }
};