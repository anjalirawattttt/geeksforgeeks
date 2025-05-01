//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Back-end complete function Template for C++

class Solution {
  public:
    vector<vector<int>> transitiveClosure(int N, vector<vector<int>> graph) {
        // code here
        vector<vector<int>> v(N,vector<int>(N,0));
        v=graph;
        for(int i=0;i<N;i++)v[i][i]=1;
        
        for(int k=0;k<N;k++){
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    if(v[i][k]==1 && v[k][j]==1)v[i][j]=1;
                }
            }
        }
        
        return v;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> graph(N, vector<int>(N, -1));
        for(int i = 0;i < N;i++)
            for(int j=0;j<N;j++)
            cin>>graph[i][j];
        
        Solution ob;
        vector<vector<int>> ans = ob.transitiveClosure(N, graph);
        for(int i = 0;i < N;i++)
            {for(int j = 0;j < N;j++)
                cout<<ans[i][j]<<" ";
        cout<<"\n";}
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends