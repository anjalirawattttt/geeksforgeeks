class Solution {
  public:
    int findPages(vector<int> &arr, int k) {
        int n=arr.size();
        if(k>n)return -1;
        
        int maxPages=0,sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            maxPages=max(maxPages,arr[i]);
        }
        int ans=-1;
        
        int l=maxPages,r=sum;
        while(l<=r){
            int mid = l +(r-l)/2;
            int s=1,temp=0;
            
            for(int i=0;i<n;i++){
                if(temp+arr[i]<=mid)temp+=arr[i];  
                else{
                    s++;
                    temp=arr[i];
                }
            }
            
            if(s<=k){
                ans=mid;
                r=mid-1;    
            }
            else{
                l=mid+1;    
            }
            
        }
        return ans;
    }
};