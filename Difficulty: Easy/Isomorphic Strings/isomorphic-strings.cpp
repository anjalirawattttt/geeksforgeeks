//{ Driver Code Starts
// C++ program to check if two strings are isomorphic

#include <bits/stdc++.h>

using namespace std;
#define MAX_CHARS 256


// } Driver Code Ends

class Solution {
  public:
    // Function to check if two strings are isomorphic.
    bool areIsomorphic(string &s1, string &s2) {
        
        if(s1.length()!=s2.length())return false;
        unordered_map<char,int> m1,m2;
       
        for(int i=0;i<=s1.length();i++){
            if(m1.find(s1[i])==m1.end()) m1[s1[i]]=i;
            if(m2.find(s2[i])==m2.end()) m2[s2[i]]=i;
            
            if(m1[s1[i]]!=m2[s2[i]])return false;
            
        }
        
        
        return true;
        
    }
};


//{ Driver Code Starts.

// Driver program
int main() {
    int t;
    cin >> t;
    string s1, s2;
    while (t--) {
        cin >> s1;
        cin >> s2;
        Solution obj;
        int r = obj.areIsomorphic(s1, s2);
        if (r) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends