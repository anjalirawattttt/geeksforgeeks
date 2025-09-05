class Solution {
  public:
    int help(int W, vector<int> &val, vector<int> &wt,int i,vector<vector<int>> &dp){
        if(i<0)return 0;
        if(W==0)return 0;
        if(dp[i][W]!=-1)return dp[i][W];
        //pick
        int op1=0;
        if(wt[i]<=W)op1=val[i]+help(W-wt[i],val,wt,i-1,dp);
        //not pick
        int op2=help(W,val,wt,i-1,dp);
        return dp[i][W]=max(op1,op2);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n=wt.size();
        vector<vector<int>> dp(n,vector<int>(W+1,-1));
        return help(W,val,wt,n-1,dp);   
    }
};