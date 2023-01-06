#include <iostream>
using namespace std;
#include <stack>

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

Node* Add2LL(Node *head1, Node* head2){
    stack<Node*> st1;
    stack<Node*> st2;
    Node *temp1 = head1;
    Node *temp2 = head2;
    while(temp1 != NULL){
        st1.push(temp1);
        temp1 = temp1 -> next;
    }
    while(temp2 != NULL){
        st2.push(temp2);
        temp2 = temp2 -> next;
    }
    int carry = 0;
    Node *head = NULL;
    while(!st1.empty() && !st2.empty()){
        int ans = (st1.top() -> data) + (st2.top() -> data) + carry;
        st1.pop();
        st2.pop();
        carry = ans/10;
        ans = ans%10;
        Node * temp = new Node(ans);
        if(head == NULL){
            head = temp;
        }else{
            temp -> next = head;
            head = temp;
        }
    }
    while(!st1.empty()){
        int ans = (st1.top() -> data) + carry;
        st1.pop();
        carry = ans/10;
        ans = ans%10;
        Node * temp = new Node(ans);
        if(head == NULL){
            head = temp;
        }else{
            temp -> next = head;
            head = temp;
        }
    }
    while(!st2.empty()){
        int ans = (st2.top() -> data) + carry;
        st2.pop();
        carry = ans/10;
        ans = ans%10;
        Node * temp = new Node(ans);
        if(head == NULL){
            head = temp;
        }else{
            temp -> next = head;
            head = temp;
        }
    }
    return head;
}

int main(){
    Node *head1 = new Node(0);
    Node *head2 = new Node(1);
    Node *temp1 = head1;
    Node *temp2 = head2;
    for(int i = 1; i < 4; i++){
        Node * newNode1 = new Node(i);
        Node * newNode2 = new Node(i-1);
        temp1 -> next = newNode1;
        temp2 -> next = newNode2;
        temp1 = temp1 -> next;
        temp2 = temp2 -> next;
    }
    cout << "original LL" << endl;
    print(head1);
    print(head2);
    Node* head = Add2LL(head1, head2);
    cout << "Folded LL " << endl;
    print(head);
}
