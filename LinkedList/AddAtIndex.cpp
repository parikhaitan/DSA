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

Node* addAtIndex( Node *head, int num, int index){
    Node *newNode = new Node(num);
    if(index == 0){
        newNode -> next = head;
        head = newNode;
        return head;
    }
    Node* temp = head;
    for(int i = 0; i < index - 1; i++){
        temp = temp -> next;
    }
    newNode -> next = temp -> next;
    temp -> next = newNode;
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
    head = addAtIndex(head, 10, 2);
    cout << "after adding 10 at index 2" << endl;
    print(head);
}
