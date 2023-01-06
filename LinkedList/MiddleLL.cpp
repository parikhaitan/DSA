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

int middleLL(Node *head){
    Node *slow = head;
    Node *fast = head;
    while(fast != NULL && fast -> next != NULL && fast -> next -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow -> data;
}


int main(){
    Node *head = new Node(0);
    Node *temp = head;
    for(int i = 1; i < 6; i++){
        Node * newNode = new Node(i);
        temp -> next = newNode;
        temp = temp -> next;
    }
    cout << "original LL" << endl;
    print(head);
    cout << "Middle Element is " << middleLL(head) << endl;
}


