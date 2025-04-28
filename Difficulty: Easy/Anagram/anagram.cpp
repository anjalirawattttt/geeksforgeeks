//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        // Your code here
        unordered_map<char,int> m1;
        unordered_map<char,int> m2;
        for(int i=0;i<s1.length();i++){
            m1[s1[i]]++;
        }
        for(int i=0;i<s2.length();i++){
            m2[s2[i]]++;
        }
        if(m1==m2)return true;
        m1.clear();
        m2.clear();
        return false;
    }
};


//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.areAnagrams(c, d))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends