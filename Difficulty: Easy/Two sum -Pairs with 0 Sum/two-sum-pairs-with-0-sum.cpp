// User function template for C++

class Solution {
  public:
    vector<vector<int>> getPairs(vector<int>& arr) {
        vector<vector<int>> ans;
        vector<pair<int,int>> v;
        int n=arr.size();
        for(int i=0;i<n;i++){
            v.push_back({arr[i],i});
        }
        sort(v.begin(),v.end());
        int l=0,r=n-1;
        while(l<r){
            int sum=v[l].first+v[r].first;
            if(sum==0){
                vector<int> temp={v[l].first,v[r].first};
                if(temp[0]>temp[1])swap(temp[0],temp[1]);
                ans.push_back(temp);   
                while(l<n-1 && v[l+1].first==v[l].first)l++;
                l++;
            }
            else if(sum<0){
                l++;    
            }
            else{
                r--;    
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};