class Solution {
  public:
    int findPages(vector<int> &arr, int k) {
        int maxEle=0,sum=0;
        for(int i=0;i<arr.size();i++){
            maxEle=max(maxEle,arr[i]);
            sum+=arr[i];
        }
        
        if(k>arr.size())return -1;
        
        int l=maxEle,r=sum;
        int ans=sum;
        while(l<=r){
            int mid=l+(r-l)/2;
            int s=1,temp=arr[0];
            for(int i=1;i<arr.size();i++){
                if(temp+arr[i]<=mid){
                    temp+=arr[i];
                }  
                else{
                    s++;
                    temp=arr[i];
                }
            }
            if(s<=k){
                ans=min(ans,mid);
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
        
    }
};