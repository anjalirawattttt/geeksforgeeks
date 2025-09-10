// User function Template for C++

class Solution {
  public:
    string preToPost(string pre_exp) {
        reverse(pre_exp.begin(),pre_exp.end());
        stack<string> s;
        for(int i=0;i<pre_exp.length();i++){
            if(pre_exp[i]=='*' || pre_exp[i]=='/' || pre_exp[i]=='+' || pre_exp[i]=='-' || pre_exp[i]=='^'){
                string temp="";
                string x=s.top();
                s.pop();
                string y=s.top();
                s.pop();
                temp+=x;
                temp+=y;
                temp+=pre_exp[i];
                s.push(temp);
            }
            else{
                s.push(string(1,pre_exp[i]));    
            }
        }
        return s.top();
    }
};