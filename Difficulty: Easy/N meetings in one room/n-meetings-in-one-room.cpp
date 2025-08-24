class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    static bool myCmp(pair<int,int> a,pair<int,int> b){
        return a.second<b.second;
    }
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n=start.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({start[i],end[i]});
        }
        sort(v.begin(),v.end(),myCmp);
        
        int ans=1;
        int l=v[0].first,r=v[0].second;
        for(int i=1;i<n;i++){
            int s=v[i].first;
            int e=v[i].second;
            if(s>r){
                l=s;
                r=e;
                ans++;
            }
        }
        
        return ans;    
    }
};