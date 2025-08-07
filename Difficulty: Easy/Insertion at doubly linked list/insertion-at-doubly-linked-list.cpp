/*
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};
*/

class Solution {
  public:
    Node *addNode(Node *head, int p, int x) {
        Node* node=new Node(x);
        if(!head)return node;
        
        Node* temp=head;
        for(int i=0;i<p;i++){
            temp=temp->next;
        }
        Node* next=temp->next;
        
        node->next=temp->next;
        temp->next=node;
        node->prev=temp;
        
        if(next)next->prev=node;
        
        return head;
        
    }
};