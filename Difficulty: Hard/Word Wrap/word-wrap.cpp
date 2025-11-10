// User function Template for C++

class Solution {
  public:
    int help(int idx,vector<int>& arr,int k,vector<int> &dp){
        if(idx>=arr.size())return 0;
        if(dp[idx]!=-1)return dp[idx];
        
        int line=0;
        int minCost=INT_MAX;
        for(int i=idx;i<arr.size();i++){
            //first word
            if(i==idx){
                line+=arr[i];
            }
            //space then next word
            else{
                line+=1+arr[i];
            }
            
            if(line>k)break;
            
            int cost;
            if(i==arr.size()-1)cost=0;
            else cost=(k-line)*(k-line)+help(i+1,arr,k,dp);
            
            minCost=min(minCost,cost);    
        }
        
        return dp[idx]=minCost;
    }
    int solveWordWrap(vector<int> arr, int k) {
        // Code here
        int n=arr.size();
        vector<int> dp(n,-1);
        return help(0,arr,k,dp);
    }
};