// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        double ans=0;
        int n=val.size();
        
        vector<pair<double,int>> v(n);
        for(int i=0;i<n;i++){
            v[i].first=(double)val[i]/wt[i];
            v[i].second=i;
        }
        
        sort(v.begin(), v.end(), [](pair<double, int> a, pair<double, int> b) {
            return a.first > b.first;  // Decreasing order by first element
        });
        
        for(int i=0;i<n;i++){
            if(wt[v[i].second]<=capacity){
                capacity-=wt[v[i].second];
                ans+=val[v[i].second];
            }
            else{
                ans+=v[i].first*capacity; 
                break;
            }
        }
        ans = round(ans * 1e6) / 1e6;
        return ans;
    }
};
