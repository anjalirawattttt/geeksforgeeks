//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
	public:
	//Function to find the level of node X.
    void dfs(int i,vector<int> adj[],vector<bool> &visited,int &res,int X,int level){
	    visited[i]=true;
	    if(i==X){
	        res=level;
	        return;
	    }
	    for(int &v : adj[i]){
	        if(visited[v]==false){
	            dfs(v,adj,visited,res,X,level+1);
	        }
	        
	    }
	}
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    // code here
	    int res=-1;
	    vector<bool> visited(V,false);
	    
	    dfs(0,adj,visited,res,X,0);
	        
	    return res;
	}
};


//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    
cout << "~" << "\n";
}

    return 0;
}


// } Driver Code Ends