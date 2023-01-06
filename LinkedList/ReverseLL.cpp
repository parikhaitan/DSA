#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node * next;

    Node(int val){
        this -> data = val;
        next = NULL;
    }
};

void print(Node *head){
    Node *temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }cout << endl;
}

Node* ReverseLL(Node *head){
    if(head == NULL || head -> next == NULL){
        return head;
    }
    Node* prevStart = head;
    Node* prevEnd = head;
    Node* nxt = head -> next;
    while(nxt != NULL){
        prevEnd -> next = nxt -> next;
        nxt -> next = prevStart;
        head = nxt;
        nxt = prevEnd -> next;
        prevStart = head;
    }
    return head;
}

int main(){
    Node *head = new Node(0);
    Node *temp = head;
    for(int i = 1; i < 5; i++){
        Node * newNode = new Node(i);
        temp -> next = newNode;
        temp = temp -> next;
    }
    cout << "original LL" << endl;
    print(head);
    head = ReverseLL(head);
    cout << "Reversed LL " << endl;
    print(head);
}
