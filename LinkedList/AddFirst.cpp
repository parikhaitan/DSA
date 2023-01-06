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

Node* addFirst(Node *head, int num){
    Node *newNode = new Node(num);
    newNode -> next = head;
    head = newNode;
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
    head = addFirst(head, 10);
    cout << "after adding 10" << endl;
    print(head);
}


