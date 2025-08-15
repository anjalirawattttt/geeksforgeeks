class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        vector<int> res;
        vector<int> inDegrees(V,0);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            inDegrees[edge[1]]++;
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(inDegrees[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            res.push_back(u);
            for(int v:adj[u]){
                inDegrees[v]--;
                if(inDegrees[v]==0)q.push(v);
            }
        }
        
        return res;
    }
};