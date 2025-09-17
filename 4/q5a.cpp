
#include <iostream>
using namespace std;

#define MAX 100

struct Queue {
    int arr[MAX];
    int front, rear;

    Queue() {
        front = 0;
        rear = -1;
    }

    bool isEmpty() {
        return front > rear;
    }

    void enqueue(int val) {
        arr[++rear] = val;
    }

    int dequeue() {
        return arr[front++];
    }
};

struct Stack2Q {
    Queue q1, q2;

    void push(int val) {
        q1.enqueue(val);
    }

    int pop() {
        if (q1.isEmpty()) {
            cout << "Stack Underflow\n";
            return -1;
        }

        while (q1.rear+1-q1.front > 1) {
            q2.enqueue(q1.dequeue());
        }

        int top = q1.dequeue();

        Queue temp = q1;
        q1 = q2;
        q2 = temp;
        q2.front = 0;
        q2.rear = -1;

        return top;
    }

    int top() {
        if (q1.isEmpty()) return -1;

        while (q1.rear+1-q1.front > 1) {
            q2.enqueue(q1.dequeue());
        }

        int top = q1.dequeue();
        q2.enqueue(top);

        Queue temp = q1;
        q1 = q2;
        q2 = temp;
        q2.front = 0;
        q2.rear = -1;

        return top;
    }

    bool isEmpty() {
        return q1.isEmpty();
    }
};
int main() {
    Stack2Q s2q;
    s2q.push(10);
    s2q.push(20);
    s2q.push(30);
    cout << "Stack using Two Queues:\n";
    cout << "Top: " << s2q.top() << endl;
    cout << "Popped: " << s2q.pop() << endl;
    cout << "Top: " << s2q.top() << endl;
}
