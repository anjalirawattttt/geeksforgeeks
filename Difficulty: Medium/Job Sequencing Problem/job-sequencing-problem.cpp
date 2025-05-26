class Solution {
  public:
    vector<int> parent;

    // DSU find with path compression
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    // DSU merge to mark a slot as used
    void merge(int u, int v) {
        parent[u] = v;
    }
    
    
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        vector<int> v(2,0);
        int n=deadline.size();
        if(n==0)return v;
        //combine deadline and profit
        vector<pair<int,int>> jobs(n);
        for(int i=0;i<n;i++){
            jobs[i].first=profit[i];
            jobs[i].second=deadline[i];
        }
        //sort profit in decreasing order
        sort(jobs.begin(),jobs.end(),[](pair<int,int> a,pair<int,int> b){
            return a.first>b.first;
        });
        //find max deadline
        int maxx=deadline[0];
        for(int &d:deadline){
            maxx=max(maxx,d);
        }
        
        parent.resize(maxx+1);
        for (int i = 0; i <= maxx; i++) parent[i] = i;
        
        for (auto &job : jobs) {
            int p=job.first,d=job.second;
            int slot = find(d);
            if (slot > 0) {
                merge(slot, slot - 1);
                v[0]++;
                v[1] += p;
            }
        }
        
        return v;
    }
};