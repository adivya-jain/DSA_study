
// Leetcode 225. Implement Stack using Queues

#include <queue>
#include <iostream>
class MyStack {
    queue<int> q1, q2;

public:
    MyStack() {
        // queue que = new queue();
        return;
    }

    void push(int x) { q1.push(x); }

    int pop() {
        if (q1.empty()) {
            return -1;
        }
         while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        // Get the last element
        int topElement = q1.front();
        q1.pop();

        // Swap the queues
        swap(q1, q2);
        return topElement;
    }

    int top() {
          if (q1.empty()) {
            return -1; // Or throw an exception
        }

        // Move all elements except the last one to q2
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        // Get the last element
        int topElement = q1.front();

        // Push the last element to q2
        q2.push(topElement);
        q1.pop();

        // Swap the queues
        std::swap(q1, q2);

        return topElement;
    }

    bool empty() {
return q1.empty();
    }
};