
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
    static ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode *prev = head, *tail = prev->next;
        prev->next = nullptr;
        while(tail != nullptr) {
            ListNode* tmp = tail->next;
            tail->next = prev;
            prev = tail;
            tail = tmp;
        }
        return prev;
    }
/*
 * use recursion
 */
//public:
//    ListNode* reverseList(ListNode* head) {
//        if (head == nullptr) return head;
//        reverse(head);
//        return new_start->next;
//    }
//    ~Solution() {
//        delete new_start;
//    }
//private:
//    ListNode* new_start = new ListNode();
//    ListNode* reverse(ListNode* head) {
//        if (head->next == nullptr) {
//            new_start->next = head;
//            return head;
//        }
//        ListNode* tail = reverse(head->next);
//        head->next = nullptr;
//        tail->next = head;
//        return head;
//    }
};