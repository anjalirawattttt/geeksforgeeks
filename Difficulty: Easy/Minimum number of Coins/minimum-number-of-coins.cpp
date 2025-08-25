// User function Template for C++

class Solution {
  public:
    vector<int> minPartition(int N) {
        // code here
        vector<int> ans;
        int amount=N;
        vector<int> c={2000,500,200,100,50,20,10,5,2,1};
        for(int i=0;i<c.size();i++){
            while(amount>=c[i]){
                ans.push_back(c[i]);
                amount-=c[i];
            }
            if(amount==0)break;
        }
        
        return ans;
    }
};