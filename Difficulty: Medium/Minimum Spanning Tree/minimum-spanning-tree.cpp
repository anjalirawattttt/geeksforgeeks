class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);
        for(auto &e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        
        using T=tuple<int,int,int>;//weight,node,parent
        priority_queue<T,vector<T>,greater<T>> pq;
        vector<bool> visited(V,false);
        pq.push({0,0,-1});
        
        int ans=0;
        
        while(!pq.empty()){
            auto [wt,u,p]=pq.top();
            pq.pop();
            if(visited[u])continue;
            visited[u]=true;
            ans+=wt;
            for(auto &[v,w]:adj[u]){
                if(!visited[v]){
                    pq.push({w,v,u});
                }    
            }
        }
        return ans;
        
    }
};