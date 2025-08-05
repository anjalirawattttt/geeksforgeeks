/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    void buildMap(Node* node,Node* parent,unordered_map<Node*,Node*> &m){
        if(!node)return;
        m[node]=parent;
        buildMap(node->left,node,m);
        buildMap(node->right,node,m);
    }
    
    Node* findNode(Node* root, int target){
        if(!root)return NULL;
        if(root->data==target)return root;
        Node* l=findNode(root->left,target);
        if(l)return l;
        return findNode(root->right,target);
    }
    
    int minTime(Node* root, int target) {
        if(!root)return 0;
        
        unordered_map<Node*,Node*> m;
        buildMap(root,NULL,m);
        
        queue<Node*> q;
        unordered_set<Node*> visited;
        Node* t=findNode(root,target);
        
        q.push(t);
        visited.insert(t);
        int time=0;
        
        while(!q.empty()){
            int size=q.size();
            bool burned=false;
            while(size--){
                Node* node=q.front();
                q.pop();
                if(node->left && visited.find(node->left)==visited.end()){
                    visited.insert(node->left); 
                    q.push(node->left);
                    burned=true;
                }
                if(node->right && visited.find(node->right)==visited.end()){
                    visited.insert(node->right); 
                    q.push(node->right);
                    burned=true;
                }
                if(m[node] && visited.find(m[node])==visited.end()){
                    visited.insert(m[node]);   
                    q.push(m[node]);
                    burned=true;
                }   
            }
            
            if(burned)time++;
            
        }
        return time;
    }
};