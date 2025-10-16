
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


void insertAtBeginning(int val) {
    struct Node* temp = createNode(val);
    if (head == NULL) {
        head = tail = temp;
    } else {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
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


void insertAfter(int key, int val) {
    struct Node* p = head;
    while (p != NULL && p->data != key) {
        p = p->next;
    }
    if (p == NULL) {
        cout << "Node " << key << " not found!" << endl;
        return;
    }

    struct Node* temp = createNode(val);
    temp->next = p->next;
    temp->prev = p;

    if (p->next != NULL) {
        p->next->prev = temp;
    } else {
        tail = temp; 
    }

    p->next = temp;
}


void insertBefore(int key, int val) {
    struct Node* p = head;
    while (p != NULL && p->data != key) {
        p = p->next;
    }
    if (p == NULL) {
        cout << "Node " << key << " not found!" << endl;
        return;
    }

    struct Node* temp = createNode(val);
    temp->next = p;
    temp->prev = p->prev;

    if (p->prev != NULL) {
        p->prev->next = temp;
    } else {
        head = temp; 
    }

    p->prev = temp;
}


void deleteNode(int key) {
    struct Node* p = head;
    while (p != NULL && p->data != key) {
        p = p->next;
    }
    if (p == NULL) {
        cout << "Node " << key << " not found!" << endl;
        return;
    }

    if (p->prev != NULL) {
        p->prev->next = p->next;
    } else {
        head = p->next; 
    }

    if (p->next != NULL) {
        p->next->prev = p->prev;
    } else {
        tail = p->prev; 
    }

    delete p;
    cout << "Node " << key << " deleted." << endl;
}


void searchNode(int key) {
    struct Node* p = head;
    int pos = 1;
    while (p != NULL) {
        if (p->data == key) {
            cout << "Node " << key << " found at position " << pos << endl;
            return;
        }
        p = p->next;
        pos++;
    }
    cout << "Node " << key << " not found!" << endl;
}


void displayList() {
    struct Node* p = head;
    cout << "Doubly Linked List: ";
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    int choice, val, key;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After a Node\n";
        cout << "4. Insert Before a Node\n";
        cout << "5. Delete a Node\n";
        cout << "6. Search a Node\n";
        cout << "7. Display List\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                insertAtBeginning(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                insertAtEnd(val);
                break;
            case 3:
                cout << "Enter key (after which to insert): ";
                cin >> key;
                cout << "Enter value to insert: ";
                cin >> val;
                insertAfter(key, val);
                break;
            case 4:
                cout << "Enter key (before which to insert): ";
                cin >> key;
                cout << "Enter value to insert: ";
                cin >> val;
                insertBefore(key, val);
                break;
            case 5:
                cout << "Enter value to delete: ";
                cin >> key;
                deleteNode(key);
                break;
            case 6:
                cout << "Enter value to search: ";
                cin >> key;
                searchNode(key);
                break;
            case 7:
                displayList();
                break;
            case 8:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 8);

    return 0;
}