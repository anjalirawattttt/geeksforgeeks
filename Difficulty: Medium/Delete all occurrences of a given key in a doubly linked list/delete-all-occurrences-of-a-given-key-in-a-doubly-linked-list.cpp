// User function Template for C++

/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        // Write your code here
        if( !head_ref || !(*head_ref) )return ;
        
        struct Node* temp=*head_ref;
        
        while(temp){
            struct Node* next=temp->next;
            if(temp->data==x){ 
                if(temp->prev){
                    temp->prev->next=temp->next;
                }
                else{
                    *head_ref=temp->next;
                }
                if(temp->next){
                    temp->next->prev=temp->prev;
                }
                delete temp;
            }
            temp=next; 
        }
    }
};