/*Structure of the linked list node is as
struct Node {
  int data;
  struct Node * next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        // Code here
        Node* node=new Node(x);
        if(!head)return node;
        
        Node* temp=head;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=node;
        return head;
    }
};