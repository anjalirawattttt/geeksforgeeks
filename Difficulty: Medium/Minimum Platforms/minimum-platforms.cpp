class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        int n=arr.size();
        if(n==0 || n==1)return n;
        
        
       sort(arr.begin(),arr.end());
       sort(dep.begin(),dep.end());
        
        int plat=1,maxPlat=0,i=1,j=0;
        
        while(i<n && j<n){
            if(arr[i]<=dep[j]){
                plat++;
                i++;
            }
            else{
                plat--;
                j++;
            }
            maxPlat=max(maxPlat,plat);
        }
        
        return maxPlat;
    }
};
