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
        help(root->right,input,ceil);    
    }
    
    if(root->data>input){
        ceil=root->data;
        help(root->left,input,ceil);     
    }
}

int findCeil(Node* root, int input) {
    int ceil=-1;
    help(root,input,ceil);
    return ceil;
    
}