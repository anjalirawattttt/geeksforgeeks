class Solution {
  public:
    string findOrder(vector<string> &words) {
        unordered_map<char,vector<char>> m;
        vector<int> indegrees(26,0);
        vector<bool> used(26,false);
        string ans="";
        
        for(string &word:words){
            for(char &c:word){
                used[c-'a']=true;
            }
        }
        
        for(int i=0;i<words.size()-1;i++){
            string word1=words[i];
            string word2=words[i+1];
            int j=0,n1=word1.length(),n2=word2.length();
            while(j<n1 && j<n2 && word1[j]==word2[j]){
                j++;
            }
            if(j==n2 && n1>n2)return "";
            if(j<n1 && j<n2){
                m[word1[j]].push_back(word2[j]);
            }
        }
        
        for(auto &p:m){
            used[p.first-'a']=true;
            for(auto &c:p.second){
                used[c-'a']=true;
                indegrees[c-'a']++;
            }
        }
        
        queue<char> q;
        for(int i=0;i<26;i++){
            if(used[i] && indegrees[i]==0){
                q.push('a'+i);
            }
        }
        
        while(!q.empty()){
            char c=q.front();
            q.pop();
            ans+=c;
            for(char &ch:m[c]){
                indegrees[ch-'a']--;
                if(indegrees[ch-'a']==0)q.push(ch);
            }
        }
        
        
        for(int i=0;i<26;i++){
            if(used[i] && indegrees[i]!=0)return "";
        }
        
        return ans;
        
    }
};