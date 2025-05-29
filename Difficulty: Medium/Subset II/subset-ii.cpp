// User function Template for C++

class Solution {
public:
    
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
    
    
    vector<vector<int>> printUniqueSubsets(vector<int>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        helper(ans,arr,{},0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};