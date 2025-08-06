/* struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};  */
void help(Node* root, int input,int &ceil){
    if(!root)return;
    
    if(root->data==input){
        ceil = input;
        return;
    }
    
    if(root->data<input){
        if(!root->right){
            return;
        }
        help(root->right,input,ceil);    
    }
    
    if(root->data>input){
        if(!root->left){
            ceil=root->data; 
            return;
        }
        ceil=root->data;
        help(root->left,input,ceil);     
    }
}

int findCeil(Node* root, int input) {
    int ceil=-1;
    help(root,input,ceil);
    return ceil;
    
}