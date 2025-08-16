// User function Template for C++
class Solution {
  public:
    
    
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<int> dist(V,INT_MAX);
        vector<vector<pair<int,int>>> adj(V);
        
        vector<int> topSort;
        vector<int> inDegrees(V,0);
        for(auto edge:edges){
            //buildGraph
            adj[edge[0]].push_back({edge[1],edge[2]});
            inDegrees[edge[1]]++;
        }
        
        queue<int> q;
        for(int i=0;i<V;i++){
            if(inDegrees[i]==0)q.push(i);
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            topSort.push_back(u);
            for(auto [v,w]:adj[u]){
                inDegrees[v]--;
                if(inDegrees[v]==0)q.push(v);
            }
        }
        
        dist[0]=0;
        for(int u:topSort){
            if(dist[u]!=INT_MAX){
                for(auto [v,w]:adj[u]){
                    if(dist[u]+w<dist[v]){
                        dist[v]=dist[u]+w;
                    }    
                }    
            }
            
        }
        
        for(int i=0;i<V;i++){
            if(dist[i]==INT_MAX)dist[i]=-1;
        }
        
        return dist;
    }
};
