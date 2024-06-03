// 641. Design Circular Deque [Doubly ended circluar queue]

class MyCircularDeque {
    int* arr;
    int front;
    int rear;
    int size;

public:
    MyCircularDeque(int k) {
        size = k;
        arr = new int[k];
        front = rear = -1;
    }

    bool insertFront(int value) {
        // 4 case

        // 1st full h queue
        if (isFull()) {
            return false;
        }

        // 2nd case 1st element hai

        else if (isEmpty()) {
            front = rear = 0;
        }
        // cyclic nature
        else if (front == 0 && rear != size - 1) {
            front = size - 1;
        }

        else {
            front--;
        }

        arr[front] = value;
        return true;
    }

    bool insertLast(int value) {
        // 4 case

        // 1st full h queue
        if (isFull()) {
            return false;
        }

        // 2nd case 1st element hai

        else if (isEmpty()) {
            front = rear = 0;
        }
        // cyclic nature
        else if (rear == size - 1 && front != 0) {
            rear = 0;
        }

        else {
            rear++;
        }

        arr[rear] = value;
        return true;
    }

    bool deleteFront() {
            //4cases

            // case 1 empty??

            if (isEmpty()) {
            return false;
        }

        // case 2 --> 1 element only
        else if (front == rear) {
            front = -1;
            rear = -1;
        }
        // case 3 --> cyclic nature
        else if (front == size - 1) {
            front = 0;
        }

        // case 4  Normal Case

        else {
            front++;
        }

        return true;
    }

    bool deleteLast() {
        // 4cases
        //  case 1 empty??
        if (isEmpty()) {
            return false;
        }

        // case 2 --> 1 element only
        else if (front == rear) {
            front = -1;
            rear = -1;
        }
        // case 3 --> cyclic nature
        else if (rear == 0) {
            rear = size - 1;
        }

        // case 4  Normal Case

        else {
            rear--;
        }

        return true;
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        } else
            return arr[front];
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        } else
            return arr[rear];
    }

    bool isEmpty() {

        if (front == -1) {
            return true;
        }
        else return false;
    }

    bool isFull() {

        if ((front == 0) && (rear == size - 1) ||
            (front!=0 && rear == (front - 1) % (size - 1))) {
            return true;
        }
        else return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */