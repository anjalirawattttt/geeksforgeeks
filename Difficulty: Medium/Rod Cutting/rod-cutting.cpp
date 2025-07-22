// User function Template for C++

class Solution {
  public:
    int help(int i,vector<int>& price,int n,vector<vector<int>> &dp){
        if(i==0){
            if(n==0)return 0;
            return n*price[0];
        }
        if(dp[i][n]!=-1)return dp[i][n] ;
        //cut
        int op1=INT_MIN;
        if(i<=n-1)op1=price[i]+help(i,price,n-i-1,dp);
        //not cut
        int op2=help(i-1,price,n,dp);
        return dp[i][n]=max(op1,op2);
    }
    
    int cutRod(vector<int> &price) {
        int n=price.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return help(n-1,price,n,dp);
    }
};