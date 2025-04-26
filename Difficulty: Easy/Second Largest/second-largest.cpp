//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int maxx=arr[0];
        int prev=0;
        for(int i=0;i<arr.size();i++){
            
            if(arr[i]>maxx){
                prev=maxx;
                maxx=arr[i];
            }
            else if(arr[i]>prev && arr[i]<maxx){
                    prev=arr[i];
            }
        }
        if(prev==maxx || prev==0)return -1;
        return prev;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends