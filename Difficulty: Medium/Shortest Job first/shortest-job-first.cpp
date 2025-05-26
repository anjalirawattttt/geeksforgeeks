// User function Template for C++

//Back-end complete function Template for C++

class Solution {
    
  public:
    long long solve(vector<int>& bt) {
        long long ans=0;
        long long temp=0;
        int n=bt.size();
        sort(bt.begin(),bt.end()); 
        for(int i=0;i<n;i++){
            ans+=temp;
            temp+=bt[i];
        }
        
        return ans/n;
    }
};