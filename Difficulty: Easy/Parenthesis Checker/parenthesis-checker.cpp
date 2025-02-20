//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isBalanced(string& s) {
        unordered_map<char,int> m={ {'(',-1} ,{'[',-2} , {'{',-3} , {')',1} ,{']',2} , {'}',3} };
        // code here
        stack<char> st;
        for(char ch:s){
            if(st.empty()){
                st.push(ch);
            }
            else if(m[st.top()]+m[ch] == 0 && m[st.top()]<0 && m[ch] >0){
                st.pop();
            }
            else{
               st.push(ch); 
            }
        }
        if(st.empty())return true;
        else return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends