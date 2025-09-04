class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n=arr.size();
        stack<int> s;
        vector<int> ans(n);
        
        for(int i=0;i<n;i++){
            while(!s.empty() && arr[s.top()]<=arr[i])s.pop();
            if(s.empty()){
                ans[i]=i+1;
            }
            else{
                ans[i]=i-s.top();
            }
            s.push(i);
        }
        
        return ans;
    }
};