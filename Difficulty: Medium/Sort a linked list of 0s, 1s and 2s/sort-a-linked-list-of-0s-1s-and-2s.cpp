/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
class Solution {
  public:
    Node* segregate(Node* head) {
        if(!head || !head->next)return head;
        
        //0's
        int a0=0,a1=0,a2=0;
        Node* temp=head;
        while(temp){
            if(temp->data==0)a0++;
            else if(temp->data==1)a1++;
            else a2++;
            temp=temp->next;   
        }
        
        temp=head;
        while(a0--){
            temp->data=0;
            temp=temp->next;     
        }
        while(a1--){
            temp->data=1;
            temp=temp->next;   
        }
        while(a2--){
            temp->data=2;
            temp=temp->next;   
        }
        
        return head;
    }
};