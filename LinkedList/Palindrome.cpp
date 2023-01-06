//leetcode or cn

#include <iostream>
using namespace std;
 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

bool isPalindrome(ListNode* head) {
    if(head == NULL){
        return true;
    }
    ListNode * temp = head;
    int count = 0; 
    while(temp!= NULL){
        count++;
        temp = temp -> next;
    }
    int arr[100000];
    temp = head;
    int i=0;
    while(temp!= NULL){
        arr[i]= temp -> val;
        temp = temp-> next;
        i++;
    }
    int mid = count/2;
    for(int j=0,k=count-1 ; j<mid ;j++,k--){
        if(arr[j]!=arr[k]){
            return false;
        }
    }return true;
}


