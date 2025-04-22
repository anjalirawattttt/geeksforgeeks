//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    // Function to count paths between two vertices in a directed graph.
    void dfs(int source, int destination,vector<int> adj[],vector<bool> &visited,int &count){
        if(source==destination){
            count++;
            return;
        }
        visited[source]=true;
        for(int &v:adj[source]){
            if(visited[v]==false){
                dfs(v,destination,adj,visited,count);
            }
        }
        visited[source]=false;
    }
    // Function to count paths between two vertices in a directed graph.
    int countPaths(int V, vector<int> adj[], int source, int destination) {
        // Code here
        int count=0;
        vector<bool> visited(V,false);
        if(visited[source]==false){
            dfs(source,destination,adj,visited,count);

        }
        return count;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // adj[v].push_back(u);
        }
        int source, destination;
        cin >> source >> destination;
        Solution obj;
        cout << obj.countPaths(V, adj, source, destination) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends