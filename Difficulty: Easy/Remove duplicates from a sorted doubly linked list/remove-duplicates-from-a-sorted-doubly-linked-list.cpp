/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/

class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        // Your code here
        if(!head || !head->next)return head;
        
        Node* temp=head;
        Node* prev=NULL;
        while(temp){
            Node* next=temp->next;
            //delete
            if(prev && prev->data==temp->data){
                temp->prev->next=temp->next;
                if(temp->next)temp->next->prev=temp->prev;
                delete temp;
            }
            //no deletion
            else{
                prev=temp;    
            }
            temp=next;
        }
        return head;
    }
};