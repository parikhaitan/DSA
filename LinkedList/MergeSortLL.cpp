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

Node* mergeSort(Node* head){
    if(head == NULL || head -> next == NULL){
        return head;
    }
    Node *slow = head;
    Node *fast = head;
    Node *temp = NULL;
    while(fast!= NULL && fast -> next != NULL){
        temp = slow;
        slow = slow -> next;
        fast = fast -> next -> next;
    }temp -> next = NULL;

    head = mergeSort(head);
    slow = mergeSort(slow);
    return mergeSortedLL(head, slow);

}


int main(){
    Node *head = new Node(7);
    Node *temp1 = head;
    for(int i = 1; i < 6; i++){
        Node * newNode1 = new Node(10 - i);
        temp1 -> next = newNode1;
        temp1 = temp1 -> next;
    }
    cout << "original LL" << endl;
    print(head);
    Node *ans = mergeSort(head);
    cout << "Merged LL is " << endl;
    print(ans);
}