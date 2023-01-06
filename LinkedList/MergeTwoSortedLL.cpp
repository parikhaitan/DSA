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

Node* mergeSortedLL(Node *head1, Node *head2){
    Node *temp1 = head1;
    Node *temp2 = head2;
    Node *head = NULL;
    if(temp1 -> data < temp2 -> data){
         head = temp1;
         temp1 = temp1 -> next;   
    }else{
        head = temp2;
        temp2 = temp2 -> next;
    }
    Node *tail = head;
    while(temp1 != NULL && temp2 != NULL){
        if(temp1 -> data < temp2 -> data){
            tail -> next = temp1;
            tail = tail -> next;
            temp1 = temp1 -> next;
        }else{
            tail -> next = temp2;
            tail = tail -> next;
            temp2 = temp2 -> next;
        }
    }if(temp1 != NULL){
        tail -> next = temp1;
    }
    if(temp2 != NULL){
        tail -> next = temp2;
    }return head;
}


int main(){
    Node *head1 = new Node(0);
    Node *head2 = new Node(1);
    Node *temp1 = head1;
    Node *temp2 = head2;
    for(int i = 1; i < 6; i++){
        Node * newNode1 = new Node(i*2);
        Node * newNode2 = new Node((i*2) + i);
        temp1 -> next = newNode1;
        temp2 -> next = newNode2;
        temp1 = temp1 -> next;
        temp2 = temp2 -> next;
    }
    cout << "original LL" << endl;
    print(head1);
    print(head2);
    Node *ans = mergeSortedLL(head1, head2);
    cout << "Merged LL is " << endl;
    print(ans);
}


