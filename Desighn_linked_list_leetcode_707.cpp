class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode* next;

        ListNode(int x) {
            val = x;
            next = nullptr;
        }
    };

    ListNode* head;
    int sz;

    MyLinkedList() {
        head = nullptr;
        sz = 0;
    }

    int get(int index) {
        if (index < 0 || index >= sz)
            return -1;

        ListNode* curr = head;

        while (index--)
            curr = curr->next;

        return curr->val;
    }

    void addAtHead(int val) {
        ListNode* node = new ListNode(val);
        node->next = head;
        head = node;
        sz++;
    }

    void addAtTail(int val) {
        ListNode* node = new ListNode(val);

        if (!head) {
            head = node;
            sz++;
            return;
        }

        ListNode* curr = head;

        while (curr->next)
            curr = curr->next;

        curr->next = node;
        sz++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > sz)
            return;

        if (index == 0) {
            addAtHead(val);
            return;
        }

        ListNode* curr = head;

        for (int i = 0; i < index - 1; i++)
            curr = curr->next;

        ListNode* node = new ListNode(val);
        node->next = curr->next;
        curr->next = node;
        sz++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= sz)
            return;

        if (index == 0) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            sz--;
            return;
        }

        ListNode* curr = head;

        for (int i = 0; i < index - 1; i++)
            curr = curr->next;

        ListNode* temp = curr->next;
        curr->next = temp->next;
        delete temp;
        sz--;
    }
};