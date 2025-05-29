class Solution {
  public:
    // Function to find all possible unique subsets.
    void helper(vector<vector<int>>& ans,vector<int>& arr,vector<int> subset,int i){
        if(i==arr.size()){
            ans.push_back(subset);
            return;
        }
        
        subset.push_back(arr[i]);
        helper(ans,arr,subset,i+1);
        subset.pop_back();
        while(i+1<arr.size() && arr[i]==arr[i+1])i++;
        helper(ans,arr,subset,i+1);
    }
    
    
    vector<vector<int>> AllSubsets(vector<int>& arr,int n) {
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        helper(ans,arr,{},0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};