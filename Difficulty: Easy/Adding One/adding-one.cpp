//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> addOne(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int> v;
        
        int right=n-1;
        
        if(arr[right]<9){
            v=arr;
            v[right]++;
            return v;
        }
        if(arr[right]==9){
            v=arr;
            while(arr[right]==9 && right>=0){
                v[right]=0;
                right--;
            }
            
            if(right<0){
                v.clear();
                v.push_back(1);
                for(int i=0;i<n;i++){
                    v.push_back(0);
                }
            }
            else{
                v[right]++;  
                return v;
            }
            
            
        }
        
        
        
        return v;
        
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }

        Solution ob;
        vector<int> result = ob.addOne(nums);

        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends