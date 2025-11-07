class Solution {
  public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b) {
        // Your code here
        int n1=a.size(),n2=b.size();
        if(n2>n1)return false;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int j=0;
        for(int i=0;i<n1;i++){
            if(j<n2 && a[i]==b[j])j++;    
        }
        if(j==n2)return true;
        return false;
    }
};