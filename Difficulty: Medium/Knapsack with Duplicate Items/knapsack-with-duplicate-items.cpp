// User function Template for C++

class Solution {
  public:
    int help(int i,vector<int>& val, vector<int>& wt, int W,vector<vector<int>>& dp){
        if(i==0){
            return (W / wt[0])*val[0];
        }
        if(dp[i][W]!=-1)return dp[i][W];
        //pick
        int op1=INT_MIN;
        if(wt[i]<=W)op1=val[i]+help(i,val,wt,W-wt[i],dp);
        //not pick
        int op2=help(i-1,val,wt,W,dp);
        return dp[i][W]= max(op1,op2);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=wt.size();
        vector<vector<int>> dp(n,vector<int>(capacity+1,-1));
        return help(n-1,val,wt,capacity,dp);
    }
};