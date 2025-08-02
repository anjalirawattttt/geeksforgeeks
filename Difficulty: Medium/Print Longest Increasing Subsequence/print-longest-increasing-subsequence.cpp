class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        vector<int> res;
        
        int n=arr.size();
        vector<int> dp(n,1);
        vector<int> backtrack(n);
        for(int i=0;i<n;i++){
            backtrack[i]=i;
        }
        
        for(int idx=0;idx<n;idx++){
            for(int pidx=0;pidx<=idx-1;pidx++){
                if(arr[pidx]<arr[idx]){
                    if(1+dp[pidx]>dp[idx]){
                        dp[idx]=1+dp[pidx];
                        backtrack[idx]=pidx;
                    }
                }
            }
        }
        
        int maxIdx=-1;
        int maxi=0;
        for(int i=0;i<n;i++){
            if(dp[i]>maxi){
                maxi=dp[i];
                maxIdx=i;
            }  
        }
        
        
        while(true){
            int idx=maxIdx;
            res.push_back(arr[idx]); 
            maxIdx=backtrack[maxIdx];
            if(idx==maxIdx)break;
        }
        
        reverse(res.begin(),res.end());
        return res;
        
        
        
    }
};