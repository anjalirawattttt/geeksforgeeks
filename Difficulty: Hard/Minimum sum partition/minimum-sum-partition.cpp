class Solution {

  public:
    int minDifference(vector<int>& arr) {
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];    
        }
        
        vector<vector<bool>> dp(n,vector<bool>(sum+1,false));
        //target==0
        for(int i=0;i<n;i++)dp[i][0]=true;
        //n==0
        if(arr[0]<=sum)dp[0][arr[0]]=true;
        
        for(int i=1;i<n;i++){
            for(int t=1;t<=sum;t++){
                bool op1=false;
                if(t>=arr[i])op1=dp[i-1][t-arr[i]];
                bool op2=dp[i-1][t];
                dp[i][t]=op1|op2;
            }
        }
        int mini=INT_MAX;
        for(int sum1=0;sum1<=sum/2+1;sum1++){
            if(dp[n-1][sum1]){
                int sum2=sum-sum1;   
                mini=min(mini,abs(sum1-sum2));
            }
        }
        return mini;
    }
};
