//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    bool areKAnagrams(string &s1, string &s2, int k) {
        // code here
        if(s1.length()!=s2.length())return false;
        unordered_map<char,int> m;
        int n=s1.length();
        int count=0;
        
        for(int i=0;i<n;i++){
            m[s1[i]]++;
        }
        for(int i=0;i<n;i++){
            if(m.find(s2[i])==m.end()){
             
                count++;    
            }
            else{
                if(m[s2[i]]==0){
                    count++;
                    
                }
                    
                else m[s2[i]]--;
            }
        }
        
        if(count<=k)return true;
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        int k;
        cin >> k;
        Solution ob;
        if (ob.areKAnagrams(str1, str2, k) == true)
            cout << "true\n";
        else
            cout << "false\n";
    }
}
// } Driver Code Ends