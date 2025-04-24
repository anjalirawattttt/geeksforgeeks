//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    void dfs(int i,vector<int> adj[],vector<bool> &visited){
        visited[i]=true;
        for(int &u:adj[i]){
            if(visited[u]==false){
                dfs(u,adj,visited);
            }
        }
    }
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
	    int mv;
	    vector<bool> visited(V,false);
	    for(int i=0;i<V;i++){
	        if(visited[i]==false){
	            dfs(i,adj,visited);
	            mv=i;
	        }
	    }
	    visited.assign(V,false);
	    dfs(mv,adj,visited);
	    
	    for(bool i:visited){
	        if(i==false)return -1;
	    }
	    
	    
	    return mv;
	}

};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends