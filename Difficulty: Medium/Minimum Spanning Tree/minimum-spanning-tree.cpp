//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    class DisjointSet{
        vector<int> parent,rank;
        public:
        DisjointSet(int n){
            parent.resize(n);
            rank.resize(n,0);
            for(int i=0;i<n;i++){
                parent[i]=i;
            }
        }
        int findParent(int node){
            if(parent[node]==node)return node;
            return parent[node]= findParent(parent[node]);
            
        }
        
        void unionByRank(int u,int v){
            int pu=findParent(u);
            int pv=findParent(v);
            if(pu==pv)return;
            if(rank[pu]<rank[pv]){
                parent[pu]=pv;
            }
            else if(rank[pu]>rank[pv]){
                parent[pv]=pu;
            }
            else{
                parent[pv]=pu;
                rank[pu]++;
            }
        }
        
    };
    
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        vector<pair<int,pair<int,int>>> edges;
        int mstWeight=0;
        DisjointSet ds(V);
        
        for(int u=0;u<V;u++){
            for(auto &it:adj[u]){
                int v=it[0];
                int w=it[1];
                edges.push_back({w,{u,v}});
            }
        }
        sort(edges.begin(),edges.end());
        
        
        
        
            for(auto &edge:edges){
                int u=edge.second.first;
                int v=edge.second.second;
                int w=edge.first;
                if(ds.findParent(u)!=ds.findParent(v)){
                    ds.unionByRank(u,v);
                    mstWeight+=w;
                }
            }
            
        
        return mstWeight;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends