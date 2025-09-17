#include <iostream>
using namespace std;

#define MAX 100

struct Queue {
    int queue[MAX];
    int front,rear;

    Queue() {
        front = 0;
        rear = -1;
    }

    bool isEmpty() {
        return front > rear;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    void enqueue(int value) {
        if (isFull()) 
            cout << "Queue Overflow\n";
        else
        queue[++rear] = value;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -999;
        }
        return queue[front++];
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -999;
        }
        return queue[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
            cout << queue[i] << " ";
        cout << endl;
    }
};
struct Stack1Q {
    Queue q;

    void push(int val) {
        int size = q.rear+1-q.front;
        q.enqueue(val);

        for (int i = 0; i < size; i++)
            q.enqueue(q.dequeue());
    }

    int pop() {
        if (q.isEmpty()) {
            cout << "Stack Underflow\n";
            return -999;
        }
        return q.dequeue();
    }

    int top() {
        if (q.isEmpty()) {
            cout << "Stack Underflow\n";
            return -999;
        }
        return q.queue[q.front];
    }

    bool isEmpty() {
        return q.isEmpty();
    }
};

int main() {
    Stack1Q s1q;
    s1q.push(1);
    s1q.push(2);
    s1q.push(3);
    cout << "Stack using One Queue:\n";
    cout << "Top: " << s1q.top() << endl;
    cout << "Popped: " << s1q.pop() << endl;
    cout << "Top: " << s1q.top() << endl;

    return 0;
}
