#include <unordered_map>

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};


class Solution {
public:
    static Node* copyRandomList(Node* head) {
        // solution without extra space
        // interleaving new node with the old nodes for mapping
        // add in random pointer and unravel old and new list
        Node *prev = head;
        while (prev != nullptr) {
            Node *copy = new Node(*prev);
            prev->next = copy;
            prev = copy->next;
        }
        prev = head;
        while (prev != nullptr) {
            if (prev->random != nullptr) prev->next->random = prev->random->next;
            prev = prev->next->next;
        }
        prev = head;
        Node *new_head = new Node(0), *new_prev = new_head;
        while (prev != nullptr) {
            new_prev->next = prev->next;
            new_prev = new_prev->next;
            prev->next = prev->next->next;
            prev = prev->next;
        }
        Node* res = new_head->next;
        delete new_head;
        return res;
    }

    /*
     * hashmap solution
     */
/*    static Node* copyRandomList(Node* head) {
        std::unordered_map<Node*, Node*> mapping;
        // first copy the list following the next
        Node* new_head = new Node(0), *new_prev = new_head, *prev = head;
        while (prev != nullptr) {
            new_prev->next = new Node(*prev);
            new_prev = new_prev->next;
            mapping[prev] = new_prev;
            prev = prev->next;
        }
        new_prev->next = nullptr;
        Node *res = new_head->next;
        delete new_head;
        prev = head;
        new_prev = res;
        while (prev != nullptr) {
            if (prev->random != nullptr) new_prev->random = mapping.at(prev->random);
            prev = prev->next;
            new_prev = new_prev->next;
        }
        return res;
    }
*/
};