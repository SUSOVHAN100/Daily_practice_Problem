class MyCircularQueue {
private:
    int* q;
    int size;
    int front;
    int rear;
    int count;

public:
    MyCircularQueue(int k) {
        size = k;
        q = new int[size];
        front = 0;
        rear = 0;
        count = 0;
    }

    bool enQueue(int value) {
        if (isFull()) return false;
        q[rear] = value;
        rear++;
        if (rear == size) rear = 0; // wrap around manually
        count++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        front++;
        if (front == size) front = 0; // wrap around manually
        count--;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return q[front];
    }

    int Rear() {
        if (isEmpty()) return -1;
        int last = rear - 1;
        if (last < 0) last = size - 1;
        return q[last];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == size;
    }
};