//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>> buildGraph(int V,vector<vector<int>> & edges){
        vector<vector<int>> adj(V);
        for(auto &edge:edges){
            adj[edge[0]].push_back(edge[1]);
        }
        return adj;
    }
    
    vector<int> top(int V,vector<vector<int>> adj,vector<int>& inDegree,int &count){
        queue<int> q;
        vector<int> result;
        
        for(int i=0;i<V;i++){
            if(inDegree[i]==0)q.push(i);
        }
        while( !q.empty() ){
            int u=q.front();
            q.pop();
            count++;
            result.push_back(u);
            for(int v:adj[u]){
                inDegree[v]--;
                if(inDegree[v]==0)q.push(v);
            } 
        }
        return result;
    }
    
    
    bool isCyclic(int V, vector<vector<int>>& edges) {
        // code here
       
        vector<vector<int>> adj=buildGraph(V,edges);
        vector<int> inDegree(V,0);
        int count=0;
        vector<int>sorted;
        
        
        for(auto & edge:edges){
            inDegree[edge[1]]++;
        }
        sorted=top(V,adj,inDegree,count);
        
        
        return count!=V;
        
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
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends