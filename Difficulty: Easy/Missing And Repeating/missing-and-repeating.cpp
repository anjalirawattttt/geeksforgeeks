class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n=arr.size();
        int repeat=-1,missing=-1;
        for(int i=0;i<n;i++){
            int idx=abs(arr[i])-1;
            if(arr[idx]<0){
                repeat=idx+1;    
            }
            else{
                arr[idx]=-arr[idx];
            }
        }
        
        for(int i=0;i<n;i++){
            if(arr[i]>0){
                missing=i+1;
                break;
            }
        }
        
        return {repeat,missing};
    }
};