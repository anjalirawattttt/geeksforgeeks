// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // code here
        vector<pair<int,int>> v;
        if(!head || !head->next)return v;
        
        Node* l=head;
        Node* r=head;
        while(r->next){
            r=r->next;
        }
        
        while(l && r && l!=r){
            if(l->data>r->data)break;
            int sum=l->data+r->data;
            if(sum==target){
                v.push_back({l->data,r->data});  
                l=l->next;
                r=r->prev;
            }
            else if(sum>target){
                r=r->prev;    
            }
            else{
                l=l->next;   
            }
        }
        return v;
    }
};