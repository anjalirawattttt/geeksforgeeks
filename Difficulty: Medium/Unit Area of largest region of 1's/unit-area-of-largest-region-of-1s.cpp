//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int area(int i,int j ,vector<vector<int>> &grid,vector<vector<bool>> &visited){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() )return 0;
        visited[i][j]=true;
        int unitArea=1;
        int rNbr[]={1,1,1,0,0,-1,-1,-1};
        int cNbr[]={1,0,-1,1,-1,1,0,-1};
        for(int k=0;k<8;k++){
            int r = i + rNbr[k];
            int c = j + cNbr[k];
            if(r>=0 && c>=0 && r<grid.size() && c<grid[0].size()){
                if(grid[r][c]==1 && visited[r][c]==false){
                    unitArea+=area(r,c,grid,visited);
                    
                }
            }
        }
        return unitArea;
        
    }
    
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int maxArea=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool> (m,false));
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && visited[i][j]==false){
                    int a=area(i,j,grid,visited);
                    maxArea=max(maxArea,a);
                }
            }
        }
        
        return maxArea;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends