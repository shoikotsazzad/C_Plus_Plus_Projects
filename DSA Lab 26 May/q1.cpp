#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

Node* arrayToList(int arr[], int size) {
    if (size == 0) return nullptr;

    Node* head = new Node(arr[0]);
    Node* current = head;

    for (int i = 1; i < size; i++) {
        current->next = new Node(arr[i]);
        current = current->next;
    }

    return head;
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;

    Node* head = arrayToList(arr, size);

    cout << "Linked List: ";
    printList(head);

    return 0;
}
