class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        
        int n=a.size(),m=b.size();
        int gap=(n+m+1)/2;
        auto get=[&](int i)-> int&{
            return i<n ? a[i] : b[i-n];
        };
        
        while(true){
            int i=0,j=gap;
            while(j<n+m){
                if(get(i)>get(j)){
                    swap(get(i),get(j));
                }
                i++;
                j++;
            }
            if(gap==1)break;
            gap=(gap+1)/2;
        }
        
        
    }
};