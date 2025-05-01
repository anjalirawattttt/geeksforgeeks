//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:

    int shortestDistance(vector<string> &s, string word1, string word2) {
        // Your code goes here
        int i=-1,j=-1;
        int sd=INT_MAX;
        for(int k=0;k<s.size();k++){
            if(s[k]==word1)i=k;
            if(s[k]==word2)j=k;
            if(i!=-1 && j!=-1)sd=min(sd,abs(i-j));
        }
        return sd;
    }
};


//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;

   		vector<string> s(n);
   		for(int i = 0; i < n; i++)
   			cin >> s[i];

   		string word1, word2;

   		cin >> word1 >> word2;
   		
   		Solution ob;

   		cout << ob.shortestDistance(s, word1, word2) << "\n";
   	
cout << "~" << "\n";
}

    return 0;
}
// } Driver Code Ends