//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void dfs(int i,vector<vector<int>> &adj,vector<int> &visited,stack<int> &s){
        visited[i]=true;
        for(auto &v:adj[i]){
            if(visited[v]==false){
                dfs(v,adj,visited,s);
            }
        }
        s.push(i);
    }

    void revDfs(int &count,int i,vector<vector<int>> &adj,vector<int> &visited){
        
        visited[i]=true;
        for(auto &v:adj[i]){
            if(visited[v]==false){
                revDfs(count,v,adj,visited);
            }
        }
        
    }
    
    vector<vector<int>> transpose(int n,vector<vector<int>> &adj){
        vector<vector<int>> tAdj(n);
        for(int i=0;i<n;i++){
            for(auto& v:adj[i]){
                tAdj[v].push_back(i);
            }
        }
        return tAdj;
    }
  
  
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        int n=adj.size();
        stack<int> s;
        vector<int> topSort;
        vector<int> visited(n,false);
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                dfs(i,adj,visited,s);
            }
        }
        while(!s.empty()){
            int i=s.top();
            topSort.push_back(i);
            s.pop();
        }
        
        vector<vector<int>> tAdj=transpose(n,adj);
        for(int i=0;i<n;i++){
            visited[i]=false;
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(visited[topSort[i]]==false){
                revDfs(count,topSort[i],tAdj,visited);
                count++;
            }
        }
        
        return count;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(adj) << "\n";

        // cout << "~"
        //      << "\n";
    }

    return 0;
}

// } Driver Code Ends