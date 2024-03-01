#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LLStack {
private:
    Node* first;

public:
    LLStack() : first(nullptr) {}
    LLStack(const LLStack& other) : first(nullptr) {
        if (other.first == nullptr) return;

        Node* temp = other.first;
        Node* prev = nullptr;
        while (temp != nullptr) {
            Node* newNode = new Node(temp->data);
            if (prev == nullptr) {
                first = newNode;
            } else {
                prev->next = newNode;
            }
            prev = newNode;
            temp = temp->next;
        }
    }
    ~LLStack() {
        Node* temp = first;
        while (temp != nullptr) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
    }

    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = first;
        first = newNode;
    }

    void pop() {
        if (first == nullptr) {
            std::cout << "Stack is empty. Cannot pop." << std::endl;
            return;
        }
        Node* temp = first;
        first = first->next;
        delete temp;
    }

    void printStack() {
        Node* temp = first;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LLStack s;
    s.push(1);
    s.push(2);
    s.push(3);

    std::cout << "Original stack: ";
    s.printStack();

    LLStack t{s};

    std::cout << "Copied stack t: ";
    t.printStack();

    s.pop();

    std::cout << "Modified original stack after pop: ";
    s.printStack();

    std::cout << "Copied stack t remains unchanged: ";
    t.printStack();

    return 0;
}
