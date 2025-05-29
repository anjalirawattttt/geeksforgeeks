class Solution {
  public:
  
    void helper(string &S,vector<string> &ans,int pos){
        if(pos==S.length()){
            ans.push_back(S);
            return ;
        }
        for(int i=pos;i<S.length();i++){
            swap(S[pos],S[i]);
            helper(S,ans,pos+1);
            swap(S[pos],S[i]);
        }
    }
    
    vector<string> permutation(string S) {
        vector<string> ans;
        helper(S,ans,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};