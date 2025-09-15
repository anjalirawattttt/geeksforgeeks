class Solution {
  public:
    bool help(vector<int>& arr ,int i ,int k,vector<vector<int>> &dp){
        if(k==0)return true;
        if(i<0 || k<0)return false;
        if(dp[i][k]!=-1)return dp[i][k];
        //take
        bool op1=help(arr,i-1,k-arr[i],dp);
        //not take
        bool op2=help(arr,i-1,k,dp);
        return dp[i][k]=op1||op2;
    }
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        return help(arr,n-1,k,dp);
    }
};