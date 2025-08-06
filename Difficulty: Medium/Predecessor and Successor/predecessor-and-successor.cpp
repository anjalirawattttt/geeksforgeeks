/* BST Node
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    void help(Node* root,Node* &pre,Node* &suc,int key){
        if(!root)return;
        
        if(root->data==key){
            if(root->left){
                Node* l=root->left;
                while(l->right){
                    l=l->right;    
                }
                pre=l;
            }
            if(root->right){
                Node* r=root->right;
                while(r->left){
                    r=r->left;    
                }
                suc=r;    
            }
                
        }
        else if(root->data<key){
            pre=root;
            help(root->right,pre,suc,key);    
        }
        else{
            suc=root;
            help(root->left,pre,suc,key);    
        }
    }
    
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node* pre=NULL;
        Node* suc=NULL;
        help(root,pre,suc,key);
        
        return {pre,suc};
    }
};