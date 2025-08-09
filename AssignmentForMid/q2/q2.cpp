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
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }
}

void insertArrayToList(Node*& head, int arr[], int size) {
    for (int i = 0; i < size; i++) {
        insertAtEnd(head, arr[i]);
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

// Floyd's Cycle Detection
bool hasCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}

int main() {
    Node* head = nullptr;

    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    insertArrayToList(head, arr, size);

    cout << "Linked List: ";
    printListRecursive(head);

    //create a cycle for testing
    Node* temp = head;
    Node* cycleNode = nullptr;

    while (temp->next != nullptr) {
        if (temp->data == 30) {
            cycleNode = temp;
        }
        temp = temp->next;
    }
    temp->next = cycleNode;

    
    if (hasCycle(head)) {
        cout << "\nCycle detected in the linked list!" << endl;
    } else {
        cout << "\nNo cycle found in the linked list." << endl;
    }

    return 0;
}
