//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isSafe(int r,int c,int N){
        return (r>=0) && (c>=0) && (r<N) && (c<N); 
    }
    
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int N) {
        // Code here
        if(knightPos==targetPos)return 0;
        
        knightPos[0]--;
        knightPos[1]--;
        targetPos[0]--;
        targetPos[1]--;
        
        int steps=0;
        vector<vector<bool>> vis(N,vector<bool> (N,false));
        vector<vector<int>> cmb={{2,-1},{2,1},{-2,-1},{-2,1},{1,2},{1,-2},{-1,2},{-1,-2}};
        
        
        queue<pair<int,int>> q;
        q.push({knightPos[0],knightPos[1]});
        vis[knightPos[0]][knightPos[1]]=true;
        
        while(!q.empty()){
            int size=q.size();
            while(size--){
                
                pair<int,int> p=q.front();
                q.pop();
                for(int i=0;i<8;i++){
                    int r=p.first + cmb[i][0];
                    int c=p.second + cmb[i][1];
                    if(isSafe(r,c,N)){
                        if(r==targetPos[0] && c==targetPos[1])return steps+1;
                        if(vis[r][c]==false){
                        vis[r][c]=true;
                        q.push({r,c});
                        }
                        
                    }
                    
                }
                
            }
            steps++;
        }
        
        
        
        
        return steps;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        vector<int> knightPos(2);
        vector<int> targetPos(2);
        int N;
        cin >> N;
        cin >> knightPos[0] >> knightPos[1];
        cin >> targetPos[0] >> targetPos[1];
        Solution obj;
        int ans = obj.minStepToReachTarget(knightPos, targetPos, N);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends