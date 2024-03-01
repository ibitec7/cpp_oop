#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void printReverse(Node* head) {
    if (head == nullptr) return;
    printReverse(head->next);
    std::cout << head->data << " ";
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    std::cout << "Original linked list: ";
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;

    std::cout << "Linked list in reverse order: ";
    printReverse(head);
    std::cout << std::endl;

    return 0;
}
