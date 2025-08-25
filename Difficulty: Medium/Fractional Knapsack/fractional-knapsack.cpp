// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    static bool myCmp(pair<double,int> &a,pair<double,int> &b){
        return (a.first/a.second)>(b.first/b.second);
    }
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        double ans=0;
        int n=val.size();
        vector<pair<double,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({(double)val[i],wt[i]});
        }
        
        sort(v.begin(),v.end(),myCmp);
        int i=0;
        while(capacity!=0 && i<n){
            if(v[i].second<=capacity){
                ans+=v[i].first;
                capacity-=v[i].second;
            }   
            else{
                ans+= (v[i].first/v[i].second)*capacity ;
                capacity=0;    
            }
            i++;
        }
        ans = round(ans * 1e6) / 1e6;
        return ans;
    }
};
