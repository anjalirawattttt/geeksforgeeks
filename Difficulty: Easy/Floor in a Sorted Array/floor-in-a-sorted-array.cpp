class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        int n=arr.size();
        int l=0,r=n-1;
        int idx=-1;
        while(l<=r){
            int mid=(l+r)>>1;
            if(arr[mid]==x){
                idx=mid;
                l=mid+1;
            }
            else if(arr[mid]>x){
                r=mid-1;
            }
            else{
                idx=mid;
                l=mid+1;
            }
        }
        return idx;  
        
    }
};
