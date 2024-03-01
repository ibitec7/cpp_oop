#include <iostream>
#include <string>

using namespace std;

struct Node{
        string data;
        Node* next;
        Node(string a) : data(a), next(nullptr) {};
    };

struct DualNode{
    string data;
    DualNode* fwd;
    DualNode* bwd;
    DualNode(string a) : data(a), fwd(nullptr), bwd(nullptr) {};
};

class List{
    private:

    int size = 1;
    Node* nodes[] = {nullptr};
    DualNode* dualnodes[] = {nullptr};

    DualNode* DualNodes(string a[],int size){
        DualNode* list[size];
        for (int i = 0; i<size; i++){
            list[i] = new DualNode(a[i]);
        }
        return *list;
    }

    Node* Nodes(string a[],int size){
        Node* list[size]={nullptr};
        for (int i=0; i<size; i++){
            list[i] = new Node(a[i]);
        }
        return *list;
    }

    void ForwardLink(Node* list[],int size){
        for (int i=0; i<size-1; i++){
            list[i]->next = list[i+1];
        }
    }

    void BackwardLink(Node* list[],int size){
        for (int i=0; i<size-1; i++){
            list[i+1]->next = list[i];
        }
    }

    void CircularLink(Node* list[],int size){
        for (int i=0; i<size; i++){
            list[i]->next = list[(i+1) % size];
        }
    }

    void DualLink(DualNode* list[],int size){
        for (int i=0; i<size-1; i++){
            list[i]->fwd = list[i+1];
            list[i+1]->bwd = list[i];
        }
    }

    void DualCircularLink(DualNode* list[],int size){
        for (int i=0; i<size; i++){
            list[i]->fwd = list[(i+1) % size];
            list[i]->bwd = list[(i+size-1)% size];
        }
    }

    public:

    List(string arr[], int size, string type){

        type = tolower(type);

        switch (type){
            case "backward":
                init(size);
                BackwardLink(Nodes(arr,size),size);
                break;

            case "circular":
                init(size);
                CircularLink(Nodes(arr,size),size);
                break;

            case "dual":
                initdual(size);
                DualLink(DualNodes(arr,size),size);
                break;

            case "dualcircular":
                initdual(size);
                DualLink(DualNodes(arr,size),size);
                break;

            default:
                init(size);
                ForwardLink(Nodes(arr,size),size);
            }
        }
    }
}
