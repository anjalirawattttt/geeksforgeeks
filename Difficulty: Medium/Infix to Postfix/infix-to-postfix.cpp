class Solution {
  public:
  void help(stack<int> &st,char c,string &ans,unordered_map<char,int> m){
    if(st.empty() || m[c]>m[st.top()])st.push(c);
    else if(m[c]==m[st.top()]){
        if(c=='^'){
            st.push(c);        
        }
        else{
            ans+=st.top();
            st.pop();
            help(st,c,ans,m);
        }    
    }
    else{
        while(!st.empty() && m[c]<m[st.top()]){
            ans+=st.top();
            st.pop();    
        }
        if(st.empty() || m[c]>m[st.top()])st.push(c);
        else{
            help(st,c,ans,m);    
        }
    }
  }
    string infixToPostfix(string& s) {
        unordered_map<char,int> m={
            {'^',3},
            {'*',2},
            {'/',2},
            {'+',1},
            {'-',1}
        }; 
        stack<int> st;
        string ans="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(s[i]);    
            }
            else if(s[i]==')'){
                while(st.top()!='('){
                    ans+=st.top();
                    st.pop();
                }
                st.pop();
            }
            else if(s[i]=='^' || s[i]=='*' || s[i]=='/' || s[i]=='+' || s[i]=='-'){
                help(st,s[i],ans,m);
            }
            else{
                ans+=s[i];    
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();    
        }
        return ans;
    }
};
