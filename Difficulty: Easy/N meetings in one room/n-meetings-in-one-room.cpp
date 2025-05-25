class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        
        int n=start.size();
        if(n==0)return 0;
        
        vector<pair<int,int>> v(n);
        
        for(int i=0;i<n;i++){
            v[i].first=start[i];
            v[i].second=end[i];
        }
        
        sort(v.begin(),v.end(),[](pair<int,int> a , pair<int,int> b){
            return a.second<b.second;
        });
        
        int s=v[0].first;
        int e=v[0].second;
        int count=1;
        
        
        for(int i=1;i<n;i++){
            if(v[i].first > e){
                count++;
                s=v[i].first;
                e=v[i].second;
            }    
        }
        
        return count;
        
    }
};