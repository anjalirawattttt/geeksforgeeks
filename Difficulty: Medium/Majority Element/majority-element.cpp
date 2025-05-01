//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // code here
        //BRUTEFORCE
        if(arr.size()==1)return arr[0];
        sort(arr.begin(),arr.end());
        
        
        int count=1;
        for(int i=1;i<arr.size();i++){
            
            if(arr[i]==arr[i-1]){
                count++;
            }
            else{
                count=1;
            }
            if(count>arr.size()/2) return arr[i-1];
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.majorityElement(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends