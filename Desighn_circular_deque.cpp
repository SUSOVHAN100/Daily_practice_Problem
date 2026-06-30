class MyCircularDeque {
public:

    struct Node{
        int val;
        Node* prev;
        Node* next;

        Node(int x){
            val=x;
            prev=NULL;
            next=NULL;
        }
    };

    Node* head;
    Node* tail;

    int sz;
    int cap;

    MyCircularDeque(int k) {
        head=NULL;
        tail=NULL;
        sz=0;
        cap=k;
    }

    bool insertFront(int value) {

        if(isFull())
            return false;

        Node* node=new Node(value);

        if(head==NULL){
            head=tail=node;
        }
        else{
            node->next=head;
            head->prev=node;
            head=node;
        }

        sz++;
        return true;
    }

    bool insertLast(int value) {

        if(isFull())
            return false;

        Node* node=new Node(value);

        if(head==NULL){
            head=tail=node;
        }
        else{
            tail->next=node;
            node->prev=tail;
            tail=node;
        }

        sz++;
        return true;
    }

    bool deleteFront() {

        if(isEmpty())
            return false;

        Node* temp=head;

        if(head==tail){
            head=tail=NULL;
        }
        else{
            head=head->next;
            head->prev=NULL;
        }

        delete temp;
        sz--;

        return true;
    }

    bool deleteLast() {

        if(isEmpty())
            return false;

        Node* temp=tail;

        if(head==tail){
            head=tail=NULL;
        }
        else{
            tail=tail->prev;
            tail->next=NULL;
        }

        delete temp;
        sz--;

        return true;
    }

    int getFront() {
        if(isEmpty())
            return -1;

        return head->val;
    }

    int getRear() {
        if(isEmpty())
            return -1;

        return tail->val;
    }

    bool isEmpty() {
        return sz==0;
    }

    bool isFull() {
        return sz==cap;
    }
};