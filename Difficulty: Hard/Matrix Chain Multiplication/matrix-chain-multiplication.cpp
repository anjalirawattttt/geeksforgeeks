class Solution {
  public:
    int help(int i,int j,vector<int> &arr,vector<vector<int>> &dp){
        if(i==j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int mini=INT_MAX;
        for(int k=i;k<=j-1;k++){
            int steps=(arr[i-1]*arr[k]*arr[j])+help(i,k,arr,dp)+help(k+1,j,arr,dp);
            mini=min(mini,steps);
        }
        return dp[i][j]=mini;
    }
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return help(1,n-1,arr,dp);
        
    }
};