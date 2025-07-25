/* A binary tree node


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
    // Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2) {
        // Your Code here
        if(!r1 && !r2)return true;
        if(!r1 || !r2)return false;
        return (r1->data==r2->data) && isIdentical(r1->left,r2->left) && isIdentical(r1->right,r2->right);
        
    }
};