/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int getCount(Node* head) {
        // Code here
        int length=0;
        if(!head)return length;
        
        Node* temp=head;
        while(temp){
            length++;
            temp=temp->next;
        }
        return length;
    }
};