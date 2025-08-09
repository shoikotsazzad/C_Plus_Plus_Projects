#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
};


void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}


void insertArrayToList(Node*& head, int arr[], int size) {
    for (int i = 0; i < size; i++) {
        insertAtEnd(head, arr[i]);
    }
}


void deleteByValue(Node*& head, int value) {
    if (head == nullptr) {
        cout << "Value not found" << endl;
        return;
    }

    
    if (head->data == value) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->data != value) {
        current = current->next;
    }

    if (current->next == nullptr) {
        cout << "Value not found" << endl;
    } else {
        Node* toDelete = current->next;
        current->next = toDelete->next;
        delete toDelete;
    }
}

void printListRecursive(Node* head) {
    if (head == nullptr) {
        cout << "NULL" << endl;
        return;
    }
    cout << head->data << " -> ";
    printListRecursive(head->next);
}

int main() {
    Node* head = nullptr;

    // Insert array values
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    insertArrayToList(head, arr, size);

    cout << "Initial Linked List: ";
    printListRecursive(head);

    // Insert new node at the end
    int newValue;
    cout << "\nEnter value to insert at the end: ";
    cin >> newValue;
    insertAtEnd(head, newValue);

    cout << "After Inserting at End: ";
    printListRecursive(head);

    // Delete a node by value
    int deleteValue;
    cout << "\nEnter value to delete: ";
    cin >> deleteValue;
    deleteByValue(head, deleteValue);

    cout << "After Deletion: ";
    printListRecursive(head);

    return 0;
}
