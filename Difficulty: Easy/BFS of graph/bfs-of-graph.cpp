class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        vector<int> b;
        
        int n=adj.size();
        vector<bool> visited(n,false);
        
        queue<int> q;
        q.push(0);
        visited[0]=true;
        
        while(!q.empty()){
            int u=q.front();
            q.pop();
            b.push_back(u);
            for(int v:adj[u]){
                if(!visited[v]){
                    visited[v]=true;
                    q.push(v);
                }
            }
        }
        
        return b;
    }
};