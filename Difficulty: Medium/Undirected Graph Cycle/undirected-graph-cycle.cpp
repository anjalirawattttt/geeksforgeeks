//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool rec(vector<vector<int>>& adj,vector<bool> & visited,int s,int parent){
        visited[s]=true;
        for(int v:adj[s]){
            if(visited[v]==false){
                if(rec(adj,visited,v,s)==true)return true;
            }
            else if(v!=parent)return true;
        }
        return false;
    }
    
    vector<vector<int>> buildGraph(int V,vector<vector<int>>& edges){
        vector<vector<int>> adj(V);
        
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        return adj;
    }
    
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj=buildGraph(V,edges);
        
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            if(visited[i]==false){
                if(rec(adj,visited,i,-1)==true)return true;
            }
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCycle(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends