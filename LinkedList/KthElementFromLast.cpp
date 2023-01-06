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

int kthElementFromLast(Node *head, int k){
    Node *slow = head;
    Node *fast = head;
    for(int i = 0; i < k; i++){
        if(fast == NULL){
            cout << "less than K elements in LL" << endl;
            return -1;
        }
        fast = fast -> next;
    }
    while(fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next;
    }
    return slow -> data;
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
    cout << "3rd element from last is " << kthElementFromLast(head, 3) << endl;
}


