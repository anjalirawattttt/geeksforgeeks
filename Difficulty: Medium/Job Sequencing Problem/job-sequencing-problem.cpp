class Solution {
  public:
    static bool myCmp(pair<int,int> a , pair<int,int> b){
        return a.first>b.first;   
    }
    
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n=deadline.size();
        int maxD=0;
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({profit[i],deadline[i]});
            maxD=max(maxD,deadline[i]);
        }
        sort(v.begin(),v.end(),myCmp);
        
        vector<int> used(maxD+1,-1);
        int p=0,count=0;
        for(int i=0;i<n;i++){
            if(used[v[i].second]==-1){
                used[v[i].second]=1;
                p+=v[i].first;
                count++;
            }   
            else{
                int l=v[i].second-1;
                while(l>=1 && used[l]!=-1){
                    l--;    
                }
                if(l==0)continue;
                used[l]=1;
                p+=v[i].first;
                count++;
            }
        }
        
        return {count,p};
        
        
    }
};