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

Node* RemoveLast( Node *head){
    Node* temp = head;
    Node* prev = NULL;
    while(temp -> next != NULL){
        prev = temp; 
        temp = temp -> next;
    }
    prev -> next = NULL;
    delete temp;
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
    head = RemoveLast(head);
    cout << "after removal from last" << endl;
    print(head);
}
