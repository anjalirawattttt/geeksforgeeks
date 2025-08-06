/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
    void maxHelp(Node *root,int &maxi){
        if(!root)return;
        maxi=max(maxi,root->data);
        maxHelp(root->left,maxi);
        maxHelp(root->right,maxi);
    }
  
    int findMax(Node *root) {
        int maxi=INT_MIN;
        maxHelp(root,maxi);
        return maxi;
    }
    
    void minHelp(Node *root,int &mini){
        if(!root)return;
        mini=min(mini,root->data);
        minHelp(root->left,mini);
        minHelp(root->right,mini);
    }

    int findMin(Node *root) {
        int mini=INT_MAX;
        minHelp(root,mini);
        return mini;
    }
};