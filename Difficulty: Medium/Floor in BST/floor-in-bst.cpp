// Function to search a node in BST.
class Solution {

  public:
    void help(Node* root, int x,int &floor){
        if(!root)return;
        
        if(root->data==x){
            floor=x;
            return;
        }
        
        if(root->data<x){
            floor=root->data;
            help(root->right,x,floor);   
        }
        
        if(root->data>x){
            help(root->left,x,floor);    
        }
        
    }
    int floor(Node* root, int x) {
        int f=-1;
        help(root,x,f);
        return f;
    }
};