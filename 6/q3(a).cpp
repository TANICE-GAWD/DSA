#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;
struct Node* tail = NULL;


struct Node* createNode(int val) {
    struct Node* temp = new Node;
    temp->data = val;
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}


void insertAtEnd(int val) {
    struct Node* temp = createNode(val);
    if (head == NULL) {
        head = tail = temp;
    } else {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}


void display() {
    struct Node* p = head;
    cout << "Doubly Linked List: ";
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}


int getSize() {
    int count = 0;
    struct Node* p = head;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

int main() {
    int n, val;
    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> val;
        insertAtEnd(val);
    }

    display();

    int size = getSize();
    cout << "Size of Doubly Linked List = " << size << endl;

    return 0;
}
