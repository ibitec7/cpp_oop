#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* reverseLinkedList(Node* head) {
    Node* reverse = nullptr;
    Node* first = head;
    while (first != nullptr) {
        Node* second = first->next;
        first->next = reverse;
        reverse = first;
        first = second;
    }
    return reverse;
}

void printLinkedList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    std::cout << "Original linked list: ";
    printLinkedList(head);

    head = reverseLinkedList(head);

    std::cout << "Reversed linked list: ";
    printLinkedList(head);

    return 0;
}
