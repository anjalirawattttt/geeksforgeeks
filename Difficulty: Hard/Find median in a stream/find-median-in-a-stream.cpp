//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        priority_queue<int> left;                       // Max-heap for left half
        priority_queue<int, vector<int>, greater<int>> right;  // Min-heap for right half
        vector<double> medians;
    
        for (int num : arr) {
            // Insert into max-heap (left)
            left.push(num);
    
            // Balance heaps
            right.push(left.top());
            left.pop();
    
            if (left.size() < right.size()) {
                left.push(right.top());
                right.pop();
            }
    
            // Find median
            if (left.size() > right.size())
                medians.push_back(left.top());
            else
                medians.push_back((left.top() + right.top()) / 2.0);
        }
    
        return medians;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends