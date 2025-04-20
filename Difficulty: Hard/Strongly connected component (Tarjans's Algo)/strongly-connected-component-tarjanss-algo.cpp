//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function template for C++

class Solution
{
	public:
	void dfs(int u,int &timer,vector<int> &disc,vector<int> &low,stack<int> &st,vector<bool> &inStack,vector<int> adj[],vector<vector<int>> &sccs){
	    disc[u]=low[u]=timer++;
	    st.push(u);
	    inStack[u]=true;
	    
	    
	    for(int &v:adj[u]){
	        if(disc[v]==-1){
	            dfs(v,timer,disc,low,st,inStack,adj,sccs);
	            low[u]=min(low[u],low[v]);
	        }
	        else if(inStack[v]){
	            low[u]=min(low[u],disc[v]);
	        }
	    }
	    
	    if(disc[u]==low[u]){
	        vector<int> scc;
	        while(!st.empty()){
	            int v=st.top();
	            st.pop();
	            inStack[v]=false;
	            scc.push_back(v);
	            if(v==u)break;
	        }
	        sort(scc.begin(),scc.end());
	        sccs.push_back(scc);
	    }
	    
	}
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        
        vector<vector<int>> sccs;
        vector<bool> inStack(V,false);
        vector<int> disc(V,-1);
        vector<int> low(V,-1);
        int timer=1;
        stack<int> st;
        
        for(int i=0;i<V;i++){
            if(disc[i]==-1){
                dfs(i,timer,disc,low,st,inStack,adj,sccs);
            }
        }
        
        sort(sccs.begin(),sccs.end());
        
        
        return sccs;
    }
};


//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    
cout << "~" << "\n";
}

    return 0;
}


// } Driver Code Ends