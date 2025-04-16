//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void dfsRec(vector<vector<int>>& adj,bool visited[],vector<int>& V,int s){
        for(int v:adj[s]){
            if(visited[v]==false){
                visited[v]=true;
                V.push_back(v);
                dfsRec(adj,visited,V,v);
                  
            }
        }
    }
    
   
    
    vector<int> dfs(vector<vector<int>>& adj) {
        vector<int> V;
        int n=adj.size();
        bool visited[n];
        
        for(int i=0;i<n;i++){
            visited[i]=false;
        }
        V.push_back(0);
        visited[0]=true;
        dfsRec(adj,visited,V,0);
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
        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

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
        vector<int> ans = obj.dfs(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends