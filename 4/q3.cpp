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

    bool isFull() {
        return rear == MAX - 1;
    }

    void enqueue(int val) {
        if (!isFull()) {
            arr[++rear] = val;
        }
    }

    int dequeue() {
        if (!isEmpty()) {
            return arr[front++];
        }
        return -1; // Underflow
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void reset() {
        front = 0;
        rear = -1;
    }
};

int main() {
    Queue original, firstHalf, secondHalf, result;
    int n;

    cout << "Enter even number of elements: ";
    cin >> n;

    if (n % 2 != 0 || n > MAX) {
        cout << "Please enter an even number <= " << MAX << endl;
        return 0;
    }

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        original.enqueue(val);
    }

    int half = n / 2;

    for (int i = 0; i < half; i++) {
        firstHalf.enqueue(original.dequeue());
    }
    for (int i = 0; i < half; i++) {
        secondHalf.enqueue(original.dequeue());
    }

    while (!firstHalf.isEmpty() && !secondHalf.isEmpty()) {
        result.enqueue(firstHalf.dequeue());
        result.enqueue(secondHalf.dequeue());
    }

    cout << "Interleaved output: ";
    result.display();

    return 0;
}
