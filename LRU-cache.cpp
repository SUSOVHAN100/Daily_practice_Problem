class LRUCache {
public:
    class Node {
    public:
        int key, value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = NULL;
            next = NULL;
        }
    };

    int capacity;
    unordered_map<int, Node*> mp;   // key -> node
    Node* head;  // dummy head
    Node* tail;  // dummy tail

    LRUCache(int cap) {
        capacity = cap;

        // Create dummy nodes
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    // Add node right after head (most recently used position)
    void addNode(Node* node) {
        Node* temp = head->next;

        node->next = temp;
        node->prev = head;

        head->next = node;
        temp->prev = node;
    }

    // Remove a node from the linked list
    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    int get(int key) {
        // If key does not exist
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];

        // Move this node to front (recently used)
        deleteNode(node);
        addNode(node);

        return node->value;
    }

    void put(int key, int value) {

        // If key already exists
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->value = value;

            // Move it to front
            deleteNode(node);
            addNode(node);
        }
        else {
            // If cache is full, remove LRU item (from back)
            if (mp.size() == capacity) {
                Node* lru = tail->prev;   // Least recently used node
                mp.erase(lru->key);
                deleteNode(lru);
            }

            // Insert new node
            Node* newNode = new Node(key, value);
            addNode(newNode);
            mp[key] = newNode;
        }
    }
};
