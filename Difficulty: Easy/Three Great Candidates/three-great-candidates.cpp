//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int maxProduct(vector<int> arr) {
        // code here
        int maxx;
        int f=INT_MIN,s=INT_MIN,t=INT_MIN;
        int mf=INT_MAX,ms=INT_MAX;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>f){
                t=s;
                s=f;
                f=arr[i];
                
            }
            else if(arr[i]>s){
                t=s;
                s=arr[i];
                
            }
            else if(arr[i]>t){
                t=arr[i];
            }
            
            if(arr[i]<mf){
                ms=mf;
                mf=arr[i];
            }
            else if(arr[i]<ms){
                ms=arr[i];
            }
            
        }
        
        return max(f*s*t,mf*ms*f);
        
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
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends