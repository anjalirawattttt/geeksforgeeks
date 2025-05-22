class Solution {
  public:
    bool BST(int min,int max,Node* node){
        if(!node)return true;
        if(node->data > max || node->data<min)return false;
        return  BST(min,node->data,node->left) && BST(node->data,max,node->right);
    }
    // Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) {
        // Your code here
        if(!root)return true;
        return BST(INT_MIN,root->data,root->left) && BST(root->data,INT_MAX,root->right);
        
    }
};