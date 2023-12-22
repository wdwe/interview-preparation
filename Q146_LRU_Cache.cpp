#include <unordered_map>

class Node {
public:
    Node(Node* next=nullptr, Node* prev=nullptr, int key=0, int val=0): next(next), prev(prev), key(key), val(val) {}
    Node *next, *prev;
    int key, val;
};

class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    ~LRUCache() {
        Node *curr = start;
        while (curr != nullptr) {
            Node *tmp = curr;
            curr = curr->next;
            delete tmp;
        }
    }

    int get(int key) {
        if (!loc.contains(key)) return -1;
        // move the nodes to the front
        Node* node = loc[key];
        if (node == tail) tail = tail->prev;
        connect(node->prev, node->next);
        Node *tmp = start->next;
        connect(start, node);
        connect(node, tmp);
        if (tail == start) tail = node;
        return node->val;
    }

    void connect(Node* front, Node* back) {
        front->next = back;
        if (back != nullptr) back->prev = front;
    }

    void put(int key, int value) {
        if (loc.contains(key) || size == cap) {
            Node *node;
            if (loc.contains(key)) node = loc[key];
            else node = tail;

            // delete the nodes
            int k = node->key;
            connect(node->prev, node->next);
            if (node == tail) tail = node->prev;
            loc.erase(k);
            --size;
        }

        Node *node = new Node(nullptr, nullptr, key,value);
        Node *tmp = start->next;
        connect(start, node);
        connect(node, tmp);
        if (tail == start) tail = node;
        loc[key] = node;
        ++size;
    }

private:
    Node* start = new Node();
    Node* tail = start;
    std::unordered_map<int, Node*> loc;
    int cap;
    int size = 0;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */