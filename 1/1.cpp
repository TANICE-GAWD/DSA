#include<iostream>;


using namespace std;


const int MAX_SIZE = 100;


void create(int arr[], int &size);
void display(const int arr[], int size);
void insertElement(int arr[], int &size);
void deleteElement(int arr[], int &size);
void linearSearch(const int arr[], int size);

int main() {
    
    int arr[MAX_SIZE];
    
    int currentSize = 0;
    int choice;

    
    
    do {
        
        cout << "\n\n------ MENU ------\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        
        switch (choice) {
            case 1:
                create(arr, currentSize);
                break;
            case 2:
                display(arr, currentSize);
                break;
            case 3:
                insertElement(arr, currentSize);
                break;
            case 4:
                deleteElement(arr, currentSize);
                break;
            case 5:
                linearSearch(arr, currentSize);
                break;
            case 6:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 6.\n";
        }
    } while (choice != 6);

    return 0;
}


void create(int arr[], int &size) {
    cout << "Enter the number of elements you want to create (max " << MAX_SIZE << "): ";
    cin >> size;

    if (size > MAX_SIZE || size < 0) {
        cout << "Invalid size. Size must be between 0 and " << MAX_SIZE << ".\n";
        size = 0; 
        return;
    }

    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; ++i) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }
    cout << "Array created successfully.\n";
}


void display(const int arr[], int size) {
    if (size == 0) {
        cout << "Array is empty. Nothing to display.\n";
        return;
    }

    cout << "Array elements are: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void insertElement(int arr[], int &size) {
    if (size >= MAX_SIZE) {
        cout << "Array is full. Cannot insert new element.\n";
        return;
    }

    int pos, value;
    cout << "Enter the position to insert (1 to " << size + 1 << "): ";
    cin >> pos;

    
    pos--;

    if (pos < 0 || pos > size) {
        cout << "Invalid position!\n";
        return;
    }

    cout << "Enter the value to insert: ";
    cin >> value;

    
    for (int i = size; i > pos; --i) {
        arr[i] = arr[i - 1];
    }

    
    arr[pos] = value;
    
    size++;

    cout << "Element inserted successfully.\n";
}


void deleteElement(int arr[], int &size) {
    if (size == 0) {
        cout << "Array is empty. Cannot delete.\n";
        return;
    }

    int pos;
    cout << "Enter the position of the element to delete (1 to " << size << "): ";
    cin >> pos;

    
    pos--;

    if (pos < 0 || pos >= size) {
        cout << "Invalid position!\n";
        return;
    }

    
    for (int i = pos; i < size - 1; ++i) {
        arr[i] = arr[i + 1];
    }

    
    size--;

    cout << "Element deleted successfully.\n";
}


void linearSearch(const int arr[], int size) {
    if (size == 0) {
        cout << "Array is empty. Cannot search.\n";
        return;
    }

    int value;
    cout << "Enter the element to search for: ";
    cin >> value;

    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (arr[i] == value) {
            cout << "Element " << value << " found at position " << i + 1 << ".\n";
            found = true;
            
            break;
        }
    }

    if (!found) {
        cout << "Element " << value << " not found in the array.\n";
    }
}
