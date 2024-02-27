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
    ListNode* sortList(ListNode* head) {
        int num = 0;
        ListNode *curr = head;
        while (curr != nullptr) {
            curr = curr->next;
            num++;
        }
        ListNode* new_head = merge_sort(head, nullptr, num);
        return new_head;
    }

    ListNode* merge_sort(ListNode* head, ListNode* tail, int num) {
        if (head == tail || head->next == tail) return head;
        int mid = num / 2;
        ListNode* mid_node = head;
        for (int i = 0; i < mid; ++i)
            mid_node = mid_node->next;
        ListNode* l_head = merge_sort(head, mid_node, mid);
        ListNode* r_head = merge_sort(mid_node, tail, num - mid);

        ListNode* l = l_head, *r = r_head;
        int l_count = mid, r_count = num - mid;
        ListNode* new_head;
        if (l->val < r->val) {
            new_head = l;
            l = l->next;
            l_count--;
        } else {
            new_head = r;
            r = r->next;
            r_count--;
        }
        ListNode* curr = new_head;
        while (l_count > 0 && r_count > 0) {
            if (l->val < r->val) {
                curr->next = l;
                l = l->next;
                l_count--;
            } else {
                curr->next = r;
                r = r->next;
                r_count--;
            }
            curr = curr->next;
        }
        while (l_count > 0) {
            curr->next = l;
            l = l->next;
            curr = curr->next;
            l_count--;
        }
        while (r_count > 0) {
            curr->next = r;
            r = r->next;
            curr = curr->next;
            r_count--;
        }
        curr->next = nullptr;
        return new_head;
    }

/* parition sort
    TLE
*/
// public:
//     ListNode* sortList(ListNode* head) {
//         partition_sort(head, nullptr);
//         return head;
//     }

//     void partition_sort(ListNode* head, ListNode* tail) {
//         if (head == tail) return;
//         ListNode *curr, *partition;
//         // head is the partition value
//         // parition points to the largest value that is smaller than pval
//         // if curr->val < pval, parition ++, swap curr and partition, curr++
//         curr = head->next;
//         partition = head;
//         while (curr != tail) {
//             if (curr->val <= head->val) {
//                 partition = partition->next;
//                 swap_val(partition, curr);
//             }
//             curr = curr->next;
//         }
//         swap_val(head, partition);
//         partition_sort(head, partition);
//         partition_sort(partition->next, tail);
//     }

    void swap_val(ListNode *a, ListNode* b) {
        int tmp = a->val;
        a->val = b->val;
        b->val = tmp;
    }
};