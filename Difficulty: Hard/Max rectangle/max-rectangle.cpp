class Solution {
  public:
    int help(vector<int> &heights){
        int n=heights.size();
        int maxArea=0;
        stack<int> s;
        for(int i=0;i<=n;i++){
            int height = i==n?0:heights[i];
            while(!s.empty() && heights[s.top()]>height ){
                int h=heights[s.top()];
                s.pop();
                int w=s.empty()?i:i-s.top()-1;
                maxArea=max(maxArea,h*w);
            }
            s.push(i);
        }
        return maxArea;
    }
    int maxArea(vector<vector<int>> &mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<int> currRow(n,0);
        int mA=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0)currRow[j]=0;
                else currRow[j]++;
            }
            mA=max(mA,help(currRow));
        }
        return mA;
        
    }
};