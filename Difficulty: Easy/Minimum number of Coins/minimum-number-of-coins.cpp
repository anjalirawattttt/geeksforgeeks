// User function Template for C++

class Solution {
  public:
    vector<int> minPartition(int N) {
        vector<int> v;
        vector<int> c={2000,500,200,100,50,20,10,5,2,1};
        for(int i=0;i<c.size();i++){
            if(N==0)break;
            while(N>=c[i]){
                v.push_back(c[i]);
                N-=c[i];
            }
        }
        return v;
    }
};