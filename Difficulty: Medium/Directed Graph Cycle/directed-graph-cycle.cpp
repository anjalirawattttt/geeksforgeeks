class Solution {
  public:
    void buildGraph(vector<vector<int>> &adj,vector<vector<int>> &edges){
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
        }
    }
    
    bool dfs(int u,vector<vector<int>> &adj,vector<bool> &visited,vector<bool> &recStack){
        visited[u]=true;
        recStack[u]=true;
        for(int v:adj[u]){
            if(!visited[v]){
                if(dfs(v,adj,visited,recStack))return true;
            }
            else if(recStack[v]){
                return true;
            }
        }
        recStack[u]=false;
        return false;
    }
    
    bool isCyclic(int V, vector<vector<int>> &edges) {
        
        vector<vector<int>> adj(V);
        buildGraph(adj,edges);
        vector<bool> visited(V,false);
        vector<bool> recStack(V,false);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(i,adj,visited,recStack))return true;
            }
        }
        
        return false;
        
    }
};