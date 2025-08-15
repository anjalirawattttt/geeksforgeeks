class Solution {
  public:
    void buildGraph( vector<vector<int>> &adj, vector<vector<int>> &edges){
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
    }
    bool isBipartite(int V, vector<vector<int>> &edges) {
        //no odd length cycle
        vector<vector<int>> adj(V);
        buildGraph(adj,edges);
        vector<int> color(V,-1);
        queue<int> q;
        q.push(0);
        color[0]=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int v:adj[u]){
                if(color[v]==-1){
                    color[v]= color[u]==0?1:0 ;
                    q.push(v);
                }
                else if(color[v]==color[u])return false;
            }
        }
        return true;
    }
};