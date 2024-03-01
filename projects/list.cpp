#include <iostream>

using namespace std;

class List{
    private:
    struct Node{
        string data;
        Node* next;
    };

    Node *first = nullptr;
    int N = 0;

    public:
    List() = default;

    ~List(){
        while (first != nullptr){
            Node* second = first->next;
            delete first;
            first = second;
        }
    }

    void push(string item){
        Node* second = first->next;
        first = new Node {item, second};
        N++;
    }

    string pop(){
        Node* temp = first->next;
        string out = first->data;
        delete first;
        first = temp;
        
        

    }
}

int main(){
    struct Node{
        string data;
        Node* next;
    };
    int count = 0;

    Node* first = new Node;
    first->data = "Hello";

    Node* second = new Node;
    second->data = "World";

    Node* third = new Node;
    third->data = "endl";

    first->next = second;
    second->next = third;
    third->next = first;

    Node* current = first;

    while(current!=nullptr || count>500){
        cout<<current->data<<endl;
        current = current->next;
        count++;
    }

}