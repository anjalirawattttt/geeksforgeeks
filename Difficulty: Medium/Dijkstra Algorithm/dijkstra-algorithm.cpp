// User Function Template
class Solution {
  public:
    void buildGraph(vector<vector<pair<int,int>>> &adj,vector<vector<int>> &edges){
        for(auto edge:edges){
            adj[edge[0]].push_back({edge[1],edge[2]});
            adj[edge[1]].push_back({edge[0],edge[2]});
        }
    }
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int,int>>> adj(V);
        buildGraph(adj,edges);
        vector<int> dist(V,INT_MAX);
        
        queue<int> q;
        dist[src]=0;
        q.push(src);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto [v,wt] :adj[u]){
                if(dist[u]+wt<dist[v]){
                    dist[v]=dist[u]+wt;
                    q.push(v);
                }     
            }
        }
        return dist;
    }
};