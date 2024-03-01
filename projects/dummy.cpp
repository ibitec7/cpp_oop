#include <iostream>

using namespace std;

struct Node{
        string data;
        Node* fwd;
        Node* bwd;
        Node(string data) : data(data), fwd(nullptr), bwd(nullptr) {}
    };

void Link(Node* list[], int size){
    for (int i = 0; i<size; i++){
        list[i]->fwd = list[(i+1) % size];
        list[i]->bwd = list[(i-1+size) % size];
    }
}

int main(){
    
    Node first = Node("Hello");
    Node second = Node("World");
    Node third = Node("My");
    Node fourth = Node("Name");
    Node fifth = Node("Is");
    Node sixth = Node("Ibrahim");
    
    Node* a[6] = {&first,&second,&third,&fourth,&fifth,&sixth};
    Link(a, 6);

    Node* current = a[0];
    for (int j=0;j<4;j++){
        if (j%2==0){
            for (int i=0; i<6; i++){
                cout << current->data << " -> ";
                current = current->fwd;
            }
        }
        else{
            for (int i=0; i<6; i++){
                current = current->bwd;
                cout << current->data << " -> ";
            }
        }
    }
    cout<<endl;

}