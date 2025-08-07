/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
    // Function to delete a node at given position.
    Node* deleteNode(Node* head, int x) {
        // Your code here
        if(!head)return head;
        
        Node* temp=head;
        for(int i=1;i<x;i++){
            temp=temp->next;    
        }
        Node* prev=temp->prev;
        Node* next=temp->next;
        
        if(prev)prev->next=temp->next;
        else{
            head=head->next;
        }
        
        if(next)next->prev=temp->prev;
        delete temp;
        return head;
    }
};