#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Insert at beginning
void insertAtBeginning(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

// Insert at end
void insertAtEnd(int val) {
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

// Insert after a specific node
void insertAfterValue(int key, int val) {
    Node* temp = head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Node not found!\n";
        return;
    }
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = temp->next;
    temp->next = newNode;
}

// Deletion from beginning
void deleteFromBeginning() {
    if (head == NULL) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

// Deletion from end
void deleteFromEnd() {
    if (head == NULL) return;
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next->next != NULL) temp = temp->next;
    delete temp->next;
    temp->next = NULL;
}

// Deletion of specific node
void deleteNode(int key) {
    if (head == NULL) return;
    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL && temp->next->data != key) {
        temp = temp->next;
    }
    if (temp->next == NULL) return;
    Node* del = temp->next;
    temp->next = del->next;
    delete del;
}

// Search node
void searchNode(int key) {
    Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Found at position: " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Not found!" << endl;
}

// Display all nodes
void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    int choice, val, key;
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert After Value\n";
        cout << "4. Delete from Beginning\n5. Delete from End\n6. Delete Node by Value\n";
        cout << "7. Search Node\n8. Display\n9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1: cout << "Enter value: "; cin >> val; insertAtBeginning(val); break;
        case 2: cout << "Enter value: "; cin >> val; insertAtEnd(val); break;
        case 3: cout << "Enter key and value: "; cin >> key >> val; insertAfterValue(key, val); break;
        case 4: deleteFromBeginning(); break;
        case 5: deleteFromEnd(); break;
        case 6: cout << "Enter value to delete: "; cin >> key; deleteNode(key); break;
        case 7: cout << "Enter value to search: "; cin >> key; searchNode(key); break;
        case 8: display(); break;
        }
    } while (choice != 9);
    return 0;
}
