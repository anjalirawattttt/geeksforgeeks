class Solution {
  public:
    string smallestWindow(string &s, string &p) {
        int n1=s.length();
        int n2=p.length();
        if(n2>n1)return "";
        
        unordered_map<char,int> m;
        for(char &c:p){
            m[c]++;
        }
        
        int l=0,r=0,count=0;
        int minLen=INT_MAX;
        int start=0;
        while(r<n1){
            m[s[r]]--;
            if(m[s[r]]>=0)count++;
            while(count==n2){
                if(r-l+1<minLen){
                    minLen=r-l+1;
                    start=l;
                }
                m[s[l]]++;
                if(m[s[l]]>0)count--;
                l++;
            }
            r++;
        }
        return minLen==INT_MAX?"":s.substr(start,minLen);
        
    }
};