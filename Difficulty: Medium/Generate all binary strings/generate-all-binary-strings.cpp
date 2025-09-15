// User function Template for C++

class Solution {
  public:
    void help(string temp,vector<string> &v,int n,char ch){
        if(n==0){
            v.push_back(temp);
            return;
        }
        //0
        if(ch=='0'){
            temp+='0';
            help(temp,v,n-1,'0');
            temp.pop_back();
            temp+='1';
            help(temp,v,n-1,'1');
            temp.pop_back();
        }
        //1
        else{
            temp+='0';
            help(temp,v,n-1,'0');
            temp.pop_back();
        }
    }
    vector<string> generateBinaryStrings(int num) {
        vector<string> v;
        help("",v,num,'0');
        return v;
    }
};