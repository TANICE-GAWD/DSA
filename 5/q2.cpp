#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* head = NULL;

void insertEnd(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}

void deleteOccurrences(int key) {
    int count = 0;
    while (head != NULL && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }
    Node* temp = head;
    while (temp != NULL && temp->next != NULL) {
        if (temp->next->data == key) {
            Node* del = temp->next;
            temp->next = del->next;
            delete del;
            count++;
        } else {
            temp = temp->next;
        }
    }
    cout << "Count: " << count << endl;
}

void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next) cout << "->";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int n, val, key;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insertEnd(val);
    }
    cout << "Enter key to delete: ";
    cin >> key;
    deleteOccurrences(key);
    cout << "Updated List: ";
    display();
    return 0;
}
