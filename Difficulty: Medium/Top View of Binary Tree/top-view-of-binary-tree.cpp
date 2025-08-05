/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    
    vector<int> topView(Node *root) {
        vector<int> ans;
        if(!root)return ans;
        
        queue<pair<Node*,int>> q;
        map<int,int> m;//hd -> nodeData
        q.push({root,0});
        while(!q.empty()){
                auto [node,hd]=q.front();
                q.pop();
                if(m.find(hd)==m.end()){
                    m[hd]=node->data;
                }
                if(node->left)q.push({node->left,hd-1});
                if(node->right)q.push({node->right,hd+1});
        }
        for( auto [hd,data] : m){
            ans.push_back(data);
        }
        return ans;
    }
};