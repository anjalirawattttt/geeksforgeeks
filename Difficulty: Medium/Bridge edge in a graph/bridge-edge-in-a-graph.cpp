class Solution {
  public:
    bool dfs(int u,int parent,int &timer,vector<vector<int>> &adj,vector<int> &disc,vector<int> &low,int c,int d){  
        disc[u]=low[u]=timer++;
        for(int v:adj[u]){
            if(v==parent)continue;
            if(disc[v]==-1){
                if(dfs(v,u,timer,adj,disc,low,c,d))return true;
                low[u]=min(low[u],low[v]);
                if( ((u==c&&v==d) || (u==d&&v==c)) && low[v]>disc[u])return true;
            }
            else{
                low[u]=min(low[u],disc[v]);
            }
        }
        return false;
    }    
    
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        vector<vector<int>> adj(V);
        for(auto &edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        int timer=1;
        vector<int> disc(V,-1);
        vector<int> low(V,-1);
        for(int i=0;i<V;i++){
            if(disc[i]==-1){
                if(dfs(i,-1,timer,adj,disc,low,c,d))return true;
            }
        }
        return false;
    }
};




