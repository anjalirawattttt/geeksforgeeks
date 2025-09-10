// User function Template for C++

class Solution {
  public:
    string postToInfix(string exp) {
        stack<string> s;
        for(int i=0;i<exp.length();i++){
            if(exp[i]=='*' || exp[i]=='/' || exp[i]=='+' || exp[i]=='-' || exp[i]=='^'){
                string y=s.top();
                s.pop();
                string x=s.top();
                s.pop();
                string ans="";
                ans+='(';
                ans+=x;
                ans+=exp[i];
                ans+=y;
                ans+=')';
                s.push(ans);
            }
            else{
                s.push(string(1,exp[i]));   
            }
        }
        return s.top();
    }
    
    
    
    
};