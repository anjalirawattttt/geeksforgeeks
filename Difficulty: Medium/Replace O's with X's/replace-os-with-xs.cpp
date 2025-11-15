class Solution {
  public:
    vector<int> rows={1,-1,0,0};
    vector<int> cols={0,0,1,-1};
    void bfs(int i,int j,vector<vector<char>> &grid){
        grid[i][j]='S';
        for(int k=0;k<4;k++){
            int r=i+rows[k];
            int c=j+cols[k];
            if(r>=0 && c>=0 && r<grid.size() && c<grid[0].size() && grid[r][c]=='O'){
                bfs(r,c,grid);
            }
        }
    }
    void fill(vector<vector<char>>& grid) {
       int m=grid.size();
       int n=grid[0].size();
       for(int i=0;i<m;i++){
            if(grid[i][0]=='O'){
                bfs(i,0,grid);    
            }
            if(grid[i][n-1]=='O'){
                bfs(i,n-1,grid);  
            }
       }
       for(int j=0;j<n;j++){
            if(grid[0][j]=='O'){
                bfs(0,j,grid);    
            }
            if(grid[m-1][j]=='O'){
                bfs(m-1,j,grid);  
            }   
       }
       for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
               if(grid[i][j]=='O')grid[i][j]='X';
           }
       }
       for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
               if(grid[i][j]=='S')grid[i][j]='O';
           }
       }
    }
};