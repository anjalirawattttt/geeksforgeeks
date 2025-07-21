class Solution {
  public:
    int help(int n,vector<int>& arr,int target,vector<vector<int>>& dp){
        if(n==0){
            if(target==0) return arr[0]==0?2:1;
            else return arr[0]==target ? 1:0;
        }
        if(dp[n][target]!=-1)return dp[n][target];
        //pick
        int op1=0;
        if(arr[n]<=target)op1=help(n-1,arr,target-arr[n],dp);
        //not pick
        int op2=help(n-1,arr,target,dp);
        return dp[n][target]=(op1+op2);
    }
    
    int countPartitions(vector<int>& arr, int d) {
        //s1-s2=d
        //s1+s2=sum
        //s2=sum-d/2
        int sum=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        if((sum-d)%2!=0 || (sum-d)<0)return 0;
        
        int target=(sum-d)/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return help(n-1,arr,target,dp);
    }
};