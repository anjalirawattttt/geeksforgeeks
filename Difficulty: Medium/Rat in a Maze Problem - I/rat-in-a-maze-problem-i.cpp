class Solution {
  public:
    void help(string temp,vector<string>& ans,int i,int j,vector<vector<int>>& maze,vector<vector<bool>> &visited){
        if(i==maze.size()-1 && j==maze[0].size()-1 ){
            ans.push_back(temp);
            return ;
        }
        if(i<0 || j<0 || i>=maze.size() || j>=maze[0].size() || maze[i][j]==0 || visited[i][j])return;
        
        
        //up
        visited[i][j]=true;
        temp+='U';
        help(temp,ans,i-1,j,maze,visited);
        temp.pop_back();
        visited[i][j]=false;
        
        //down
        visited[i][j]=true;
        temp+='D';
        help(temp,ans,i+1,j,maze,visited);
        temp.pop_back();
        visited[i][j]=false; 
        
        //left
        visited[i][j]=true;
        temp+='L';
        help(temp,ans,i,j-1,maze,visited);
        temp.pop_back();
        visited[i][j]=false;
        
        //right
        visited[i][j]=true;
        temp+='R';
        help(temp,ans,i,j+1,maze,visited);
        temp.pop_back();
        visited[i][j]=false; 
        
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n=maze.size();
        vector<string> ans;
        if(maze[0][0]==0 || maze[n-1][n-1]==0)return ans;
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        help("",ans,0,0,maze,visited);
        sort(ans.begin(),ans.end());
        return ans;
    }
};