// User function Template for C++
class Solution {
  public:
    int help(int i,int j,int isTrue,string &s,vector<vector<vector<int>>>& dp){
        if(i>j)return 0;
        if(i==j){
            if(isTrue)return s[i]=='T';
            return s[i]=='F';
        }
        if(dp[i][j][isTrue]!=-1)return dp[i][j][isTrue] ;
        int ways=0;
        for(int idx=i+1;idx<=j-1;idx+=2){
            int lT=help(i,idx-1,1,s,dp);
            int rT=help(idx+1,j,1,s,dp);
            int lF=help(i,idx-1,0,s,dp);
            int rF=help(idx+1,j,0,s,dp);
            if(s[idx]=='&'){
                if(isTrue){
                    ways+=lT*rT;     
                }
                else{
                    ways+=lF*rF;
                    ways+=lF*rT;
                    ways+=lT*rF;    
                }
            }
            else if(s[idx]=='|'){
                if(isTrue){
                    ways+=lT*rT;
                    ways+=lF*rT;
                    ways+=lT*rF;     
                }
                else{
                    ways+=lF*rF;    
                }
            }
            else if(s[idx]=='^'){
                if(isTrue){
                    ways+=lF*rT;
                    ways+=lT*rF;      
                }
                else{
                    ways+=lT*rT;
                    ways+=lF*rF;
                }
            }
        }
        return dp[i][j][isTrue]=ways;
        
    }
    int countWays(string &s) {
        int n=s.length();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        return help(0,n-1,1,s,dp);
        
    }
};