//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // Your code here
        int maxArea=0;
        int n=arr.size();
        int i=0;
        stack<int> s;
        
        while(i<n){
            if (s.empty() || arr[i] >= arr[s.top()]) {
            s.push(i++);
            } else {
                // Pop the top
                int top = s.top();
                s.pop();
                // Calculate the area with arr[top] as the smallest bar
                int width = s.empty() ? i : i - s.top() - 1;
                maxArea = max(maxArea, arr[top] * width);
            }
        }
        
        while (!s.empty()) {
        int top = s.top();
        s.pop();
        int width = s.empty() ? i : i - s.top() - 1;
        maxArea = max(maxArea, arr[top] * width);
    }
        return maxArea;
    }
};



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends