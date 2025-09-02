

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        vector<int> ans;
        int n=arr.size();
        int maxEle=-1;
        for(int i=n-1;i>=0;i--){
            maxEle=max(maxEle,arr[i]); 
            if(arr[i]==maxEle){
                ans.push_back(arr[i]);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};