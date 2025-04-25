//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int orangesRotting(vector<vector<int>>& mat) {
        // Code here
        int time=0;
        int fresh=0;
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<int,int>> q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    fresh++;
                }
                else if(mat[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        
            int rNbr[]={1,-1,0,0};
            int cNbr[]={0,0,1,-1};
            
        
        while(!q.empty() && fresh>0){
            bool newRot=false;
            int size=q.size();
            for(int i=0;i<size;i++){
                pair<int,int> p=q.front();
                q.pop();
                for(int k=0;k<4;k++){
                        int r = p.first + rNbr[k];
                        int c = p.second + cNbr[k];
                        if(r>=0 && c>=0 && r<n && c<m && mat[r][c]==1){
                            mat[r][c]=2;
                            fresh--;
                            q.push({r,c});
                            newRot=true;
                        }
                        
                }
                
            }
                
            if(newRot)time++;
            
        }
        
        
        if(fresh==0){
            return time;
        }
        else{
            return -1;
        }
        
    }
    
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends