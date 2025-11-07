class Solution {
  public:
    const int MOD=1e9+7;
    int maxValue(vector<int> &arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        unsigned long long int sum=0;
        for(int i=0;i<n;i++){
            sum=(sum+((unsigned long long int)arr[i]*i)%MOD)%MOD;    
        }
        return sum;
    }
};