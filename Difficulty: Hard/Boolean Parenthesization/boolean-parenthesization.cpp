// User function Template for C++
class Solution {
  public:
    int help(int i,int j,string &s,int isTrue,vector<vector<vector<int>>> &dp){
        if(i>j)return 0;
        if(i==j){
            if(isTrue)return s[i]=='T'?1:0;
            else return s[i]=='F'?1:0;
        }
        if(dp[i][j][isTrue]!=-1)return dp[i][j][isTrue];
        int totalWays=0;
        for(int k=i+1;k<=j-1;k+=2){
            int lT=help(i,k-1,s,1,dp);
            int lF=help(i,k-1,s,0,dp);
            int rT=help(k+1,j,s,1,dp);
            int rF=help(k+1,j,s,0,dp);
            // cout<<s[k];
            int ways=0;
            if(s[k]=='&'){
                if(isTrue){
                    ways+=lT*rT;
                } 
                else{
                    ways+=lT*rF;
                    ways+=lF*rT;
                    ways+=lF*rF;
                }
            }
            else if(s[k]=='|'){
                if(isTrue){
                    ways+=lT*rF;
                    ways+=lF*rT;
                    ways+=lT*rT;
                } 
                else{
                    ways+=lF*rF;
                }    
            }
            else if(s[k]=='^'){
                if(isTrue){
                    ways+=lT*rF;
                    ways+=lF*rT;
                } 
                else{
                    ways+=lT*rT;
                    ways+=lF*rF;
                }           
            }
            totalWays+=ways;
        } 
        return dp[i][j][isTrue]=totalWays;
    }
    
    int countWays(string &s) {
        int n=s.length();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (n,vector<int>(2,-1)));
        return help(0,n-1,s,1,dp);
    }
};