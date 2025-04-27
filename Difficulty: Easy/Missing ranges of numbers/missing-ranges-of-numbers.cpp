//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>> missingRanges(vector<int> &arr, int lower, int upper) {
        // code here
        int n=arr.size();
        vector<vector<int>> v;
        
       
        if(lower<arr[0]){
            v.push_back({lower,arr[0]-1});  
        }
       
        for(int i=1;i<n;i++){
            if(arr[i]-arr[i-1]>1){
                v.push_back({arr[i-1]+1,arr[i]-1});
            }
        }
        
        if(upper>arr[n-1]){
            v.push_back({arr[n-1]+1,upper});
        }
        return v;
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        Solution ob;
        getline(cin, str);
        int lower = stoi(str);
        getline(cin, str);

        int upper = stoi(str);
        getline(cin, str);
        stringstream ss(str);
        vector<int> arr;

        int x;
        while (ss >> x)
            arr.push_back(x);
        vector<vector<int>> res = ob.missingRanges(arr, lower, upper);
        if (res.empty()) {
            cout << "[]" << endl;
        } else {
            for (const vector<int> &v : res) {
                cout << v[0] << " " << v[1] << endl;
            }
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends