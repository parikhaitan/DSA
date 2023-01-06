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

Node* FoldLL(Node *head){
    stack<Node* > st;
    if(head == NULL || head -> next == NULL){
        return head;
    }
    int count = 0;
    Node* temp = head;
    while(temp!= NULL){
        st.push(temp);
        temp = temp -> next;
        count++;
    }
    temp = head;
    for(int i = 0; i < count/2; i++){
        Node* t = temp -> next;
        temp -> next = st.top();
        st.pop();
        temp -> next -> next = t;
        temp = t;
    }
    temp -> next = NULL;
    return head;
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
    head = FoldLL(head);
    cout << "Folded LL " << endl;
    print(head);
}
