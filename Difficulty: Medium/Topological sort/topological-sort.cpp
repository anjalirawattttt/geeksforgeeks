class Solution {
  public:
    void buildGraph(vector<vector<int>> &adj,vector<vector<int>> &edges){
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
        }
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> ts;
        vector<int> inDegrees(V,0);
        for(auto edge:edges){
            inDegrees[edge[1]]++;
        }
        
        vector<vector<int>> adj(V);
        buildGraph(adj,edges);
        
        queue<int> q;
        
        for(int i=0;i<V;i++){
            if(inDegrees[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int size=q.size();
            int node=q.front();
            q.pop();
            ts.push_back(node);
            for(int v: adj[node]){
                inDegrees[v]--;
                if(inDegrees[v]==0)q.push(v);
            }
        }
        return ts;
    }
};