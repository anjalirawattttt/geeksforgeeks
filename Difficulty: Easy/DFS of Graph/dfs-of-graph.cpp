class Solution {
  public:
    void dfsHelp(int u,vector<bool> &visited,vector<vector<int>>& adj,vector<int> &d){
        visited[u]=true;
        d.push_back(u);
        for(int v:adj[u]){
            if(!visited[v]){
                dfsHelp(v,visited,adj,d);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        vector<int> d;
        int n=adj.size();
        vector<bool> visited(n,false);
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfsHelp(i,visited,adj,d);
            }
        }
        
        return d;
    }
};