/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* reverse(Node* head){
        if(!head || !head->next)return head;
        Node* prev=NULL;
        Node* curr=head;
        Node* next=head->next;
        while(curr){
            curr->next=prev;
            prev=curr;
            curr=next;
            if(next)next=next->next;
        }
        return prev;
    }
    
    Node* addOne(Node* head) {
        // Your Code here
        if(!head)return new Node(1);
        
        head=reverse(head);
        
        Node* temp=head;
        int n,carry=1;
        while(carry && temp){
            n=temp->data+carry;
            carry=n/10;
            temp->data=n%10;
            temp=temp->next;
        }
        
        
        
        if(carry){
            temp=head;
            while(temp->next){
                temp=temp->next;
            }   
            temp->next=new Node(1);
        }
        
        
        
        
        head=reverse(head);
        
        return head;
        // return head of list after adding one
    }
};