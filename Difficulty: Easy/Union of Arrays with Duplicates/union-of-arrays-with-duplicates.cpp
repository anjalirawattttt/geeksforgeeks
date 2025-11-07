class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        unordered_set<int> s;
        int n1=a.size();
        int n2=b.size();
        vector<int> ans;
        for(int i=0;i<n1;i++){
            if(s.find(a[i])==s.end()){
                s.insert(a[i]);
                ans.push_back(a[i]);
            }
        }
        for(int i=0;i<n2;i++){
            if(s.find(b[i])==s.end()){
                s.insert(b[i]);
                ans.push_back(b[i]);
            }
        }
        return ans;
    }
};