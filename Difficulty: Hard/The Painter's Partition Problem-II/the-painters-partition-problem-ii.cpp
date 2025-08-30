class Solution {
  public:
    int minTime(vector<int>& arr, int k) {
        int maxEle=0,sum=0;
        for(int i=0;i<arr.size();i++){
            maxEle=max(maxEle,arr[i]);
            sum+=arr[i];
        }
        //minimum (maximum time taken by a painter)
        
        int l=maxEle,r=sum;
        int ans=sum;
        while(l<=r){
            int mid=l+(r-l)/2;
            int p=1,temp=arr[0];
            for(int i=1;i<arr.size();i++){
                if(temp+arr[i]<=mid){
                    temp+=arr[i];
                }
                else{
                    p++;
                    temp=arr[i];
                }
            }
            
            if(p<=k){
                ans=min(ans,mid);
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
        
    }
};