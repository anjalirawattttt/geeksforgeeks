class Solution {
  public:
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(),stalls.end());
        int n=stalls.size();
        
        int maxDist=stalls[n-1]-stalls[0];
        int l=1,r=maxDist;
        int ans=1;
        while(l<=r){
            int mid=l+(r-l)/2;
            int cows=1,lastPos=0;
            for(int i=1;i<n;i++){
                if(stalls[i]-stalls[lastPos]>=mid){
                    cows++; 
                    lastPos=i;
                }
            }
            if(cows>=k){
                ans=max(ans,mid);
                l=mid+1;
            }
            else if(cows<k){
                r=mid-1;    
            }
        }
        return ans;
        
    }
};