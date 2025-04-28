//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    // Function to check if a string is Pangram or not.
    bool checkPangram(string& s) {
        // your code here
        int n=s.length();
        vector<bool> visited(26,false);
        for(int i=0;i<n;i++){
            if(s[i]>='A' && s[i]<='Z'){
                visited[s[i]-'A']=true;
            }
            if(s[i]>='a' && s[i]<='z'){
                visited[s[i]-'a']=true;
            }
        }
        for(int i=0;i<26;i++){
            if(visited[i]==false)return false;
        }
        return true;
    }
};


//{ Driver Code Starts.

// Driver Program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string s;
        getline(cin, s);
        Solution obj;
        if (obj.checkPangram(s) == true)
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
    return (0);
}

// } Driver Code Ends