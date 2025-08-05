/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void help(vector<vector<int>> &ans,vector<int>& temp,Node* root){
        if(!root){
            return;
        }
        temp.push_back(root->data);
        //leaf n
        if(!root->left && !root->right){
            ans.push_back(temp);
            temp.pop_back();
            return;
        }    
        help(ans,temp,root->left);
        help(ans,temp,root->right);
        temp.pop_back();
    }
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>> ans;
        if(!root)return ans;
        
        vector<int> temp;
        help(ans,temp,root);
        
        return ans;
    }
};