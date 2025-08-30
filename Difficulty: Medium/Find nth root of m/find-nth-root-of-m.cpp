class Solution {
  public:
    int nthRoot(int n, int m) {
        if(m==0 || m==1)return m;
        if(n==1)return m;
        int l=1,r=m/2;
        while(l<=r){
            int mid=l+(r-l)/2;
            long long temp=1;
            for(int i=0;i<n;i++){
                temp*=mid;
            }
            if(temp==m)return mid;
            else if(temp<m)l=mid+1;
            else r=mid-1;
        }
        return -1;
    }
};