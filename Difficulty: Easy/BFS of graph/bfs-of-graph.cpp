//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        vector<int> V;
        int n=adj.size();
        vector<bool> visited(n,false);
        queue<int> q;
        q.push(0);
        visited[0]=true;
        V.push_back(0);
        while(!q.empty()){
           int u=q.front();
           q.pop();
           for(int v:adj[u]){
               if(visited[v]==false){
                    q.push(v);
                    visited[v]=true;
                    V.push_back(v);
               }
           }
        }
        return V;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V;
        cin >> V;
        cin.ignore();
        // Use vector of vectors instead of array of vectors.
        vector<vector<int>> adj(V);

        for (int i = 0; i < V; i++) {
            string input;
            getline(cin, input);
            int num;
            vector<int> node;
            stringstream ss(input);
            while (ss >> num) {
                node.push_back(num);
            }
            adj[i] = node;
        }

        Solution obj;
        vector<int> ans = obj.bfs(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends