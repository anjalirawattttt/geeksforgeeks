/*
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val)
        : data(val)
        , left(nullptr)
        , right(nullptr) {}
};
*/

class Solution {
  public:
    Node* BST(int l,int r,vector<int>& nums){
        if(l>r)return NULL;
        int mid = l + (r-l) / 2;
        Node *node=new Node(nums[mid]);
        node->left=BST(l,mid-1,nums);
        node->right=BST(mid+1,r,nums);
        return node;
    }
    
    Node* sortedArrayToBST(vector<int>& nums) {
        // Code here
        Node* root;
        root=BST(0,nums.size()-1,nums);
        return root;
    }
};