/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    struct Info{
        bool isBST;
        int size;
        int minVal;
        int maxVal;
    };
    Info dfs(Node* root,int &maxi){
        if(!root)return {true,0,INT_MAX,INT_MIN};
        
        Info l=dfs(root->left,maxi);
        Info r=dfs(root->right,maxi);
        
        if(l.isBST && r.isBST && root->data>l.maxVal && root->data<r.minVal){
            int currSize=l.size+r.size+1;
            maxi=max(maxi,currSize);
            
            return {true,currSize,min(root->data,l.minVal),max(root->data,r.maxVal)};
        }
        
        return {false ,0 ,0, 0};
    }
    
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root) {
        // Your code here
        int maxi=0;
        dfs(root,maxi);
        return maxi;
    }
};