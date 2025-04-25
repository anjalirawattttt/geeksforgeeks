//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends



class Solution {
  public:
    // Function to return the minimum cost to react at bottom
    // right cell from top left cell.
    #define p pair<int,pair<int,int>>
    int minimumCostPath(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        
        priority_queue<p,vector<p>,greater<p>> q;
        dist[0][0]=grid[0][0];
        q.push({dist[0][0],{0,0}});
        
        
        int rNbr[]={1,-1,0,0};
        int cNbr[]={0,0,1,-1};
        
        while(!q.empty()){
            int d=q.top().first;
            int i=q.top().second.first;
            int j=q.top().second.second;
            q.pop();
            if(visited[i][j]==true)continue;
            visited[i][j]=true;
            
            for(int k=0;k<4;k++){
                int r = i + rNbr[k];
                int c = j + cNbr[k];
                if(r>=0 && c>=0 && r<n && c<n ){
                    if(dist[r][c]>d+grid[r][c]){
                        dist[r][c]=d+grid[r][c];
                        q.push({dist[r][c],{r,c}});
                    }
                }
            }
            
            
            
            
            
        }
        return dist[n-1][n-1];
        
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends