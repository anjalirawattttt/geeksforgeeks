// User function Template for C++

class Solution {
    public:
    void helper(vector<vector<int>>& ans,vector<int>& arr,vector<int> subset,int i){
        if(i==arr.size()){
            ans.push_back(subset);
            return;
        }
        helper(ans,arr,subset,i+1);
        subset.push_back(arr[i]);
        helper(ans,arr,subset,i+1);
        subset.pop_back();
    }
    
    
    vector<vector<int>> subsets(vector<int>& arr) {
        vector<vector<int>> ans;
        helper(ans,arr,{},0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};