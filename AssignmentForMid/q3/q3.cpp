#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* topNode = nullptr;  // Top of the stack

void push(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = topNode;
    topNode = newNode;
    cout << value << " pushed to stack." << endl;
}

// Pop operation
void pop() {
    if (topNode == nullptr) {
        cout << "Stack Underflow! Cannot pop." << endl;
        return;
    }

    Node* temp = topNode;
    cout << "Popped: " << topNode->data << endl;
    topNode = topNode->next;
    delete temp;
}

// Top operation
void top() {
    if (topNode == nullptr) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Top element: " << topNode->data << endl;
    }
}

// Display stack from top to bottom
void display() {
    if (topNode == nullptr) {
        cout << "Stack is empty." << endl;
        return;
    }

    cout << "Stack (top to bottom): ";
    Node* temp = topNode;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Example usage:
    push(10);
    push(20);
    push(30);

    display();  // Should show: 30 20 10
    top();      // Should show: 30

    pop();      // Removes 30
    display();  // Should show: 20 10
    top();      // Should show: 20

    pop(); pop(); pop();  // Pops remaining & shows underflow
    display();            

    return 0;
}
