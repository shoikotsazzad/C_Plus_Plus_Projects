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

void deleteNode(Node* &head, int index) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    if (index == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // Traverse to the node before the one to delete
    Node* current = head;
    for (int i = 0; current != nullptr && i < index - 1; i++) {
        current = current->next;
    }

    // If index is out of bounds
    if (current == nullptr || current->next == nullptr) {
        cout << "Index out of bounds!" << endl;
        return;
    }

    // Remove the node
    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
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

    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    cout << "Original list: " << endl;
    printList(head);

    deleteNode(head, 1);

    cout << "After deleting index 2: " << endl;
    printList(head);

    return 0;
}
