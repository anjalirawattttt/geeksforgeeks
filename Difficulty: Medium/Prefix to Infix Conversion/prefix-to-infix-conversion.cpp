// User function Template for C++

class Solution {
  public:
    string preToInfix(string pre_exp) {
        // Write your code here
        reverse(pre_exp.begin(),pre_exp.end());
        stack<string> s;
        for(int i=0;i<pre_exp.length();i++){
            if(pre_exp[i]=='*' || pre_exp[i]=='/' || pre_exp[i]=='+' || pre_exp[i]=='-' || pre_exp[i]=='^'){
                string temp="";
                string y=s.top();
                s.pop();
                string x=s.top();
                s.pop();
                temp+=')';
                temp+=x;
                temp+=pre_exp[i];
                temp+=y;
                temp+='(';
                s.push(temp);
            } 
            else{
                s.push(string(1,pre_exp[i]));
            }
        }
        string ans=s.top();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};



