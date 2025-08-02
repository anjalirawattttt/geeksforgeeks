
class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        vector<int> inc(n,1);
        vector<int> dec(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i] && 1+inc[j]>inc[i]){
                    inc[i]=1+inc[j];
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(nums[j]<nums[i] && 1+dec[j]>dec[i]){
                    dec[i]=1+dec[j];
                }
            }
        }
        
        int maxi=0;
        for(int i=0;i<n;i++){
            if (inc[i] > 1 && dec[i] > 1)maxi = max(maxi, inc[i] + dec[i] - 1);

        }
        return maxi;
        
    }
};
