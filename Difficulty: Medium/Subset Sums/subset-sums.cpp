class Solution {
  public:
    void helper(vector<int>& ans,vector<int>& arr,int i,int sum){
        if(i==arr.size()){
            ans.push_back(sum);
            return;
        }
        helper(ans,arr,i+1,sum);
        helper(ans,arr,i+1,sum+arr[i]);
    }
    vector<int> subsetSums(vector<int>& arr) {
        vector<int> ans;
        helper(ans,arr,0,0);
        return ans;
    }
};