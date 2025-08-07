/*
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        // Your code here
        if(!head)return head;
        
        DLLNode* prev=NULL;
        DLLNode* curr=head;
        DLLNode* next=curr->next;
        
        while(curr){
            curr->next=prev;
            curr->prev=next;
            
            prev=curr;
            curr=curr->prev;
            if(curr)next=curr->next;
        }
        return prev;
    }
};