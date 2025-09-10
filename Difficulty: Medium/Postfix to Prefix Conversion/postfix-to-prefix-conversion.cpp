// User function Template for C++

class Solution {
  public:
    string postToPre(string post_exp) {
        stack<string> s;
        for(int i=0;i<post_exp.length();i++){
            if(post_exp[i]=='*' || post_exp[i]=='/' || post_exp[i]=='+' || post_exp[i]=='-' || post_exp[i]=='^'){
                string temp="";
                temp+=post_exp[i];
                string y=s.top();
                s.pop();
                string x=s.top();
                s.pop();
                temp+=x;
                temp+=y;
                s.push(temp);
            }
            else{
                s.push(string(1,post_exp[i]));
            }
        }
        
        return s.top();
    }
};

