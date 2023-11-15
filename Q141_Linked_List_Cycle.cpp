
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    static bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;
        ListNode *slow = head, *fast = head->next;
        if (fast == slow) return true;
        while (true) {
            slow = slow->next;
            if (fast == nullptr) break;
            if ((fast = fast->next) == slow) return true;
            if (fast == nullptr) break;
            if ((fast = fast->next) == slow) return true;
        }
        return false;
    }
};