//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int>& arr) {
        // Code here
        int n=arr.size();
        
        vector<pair<int,int>> v(n);
        
        for(int i=0;i<n;i++){
            v[i].first=arr[i];
            v[i].second=i;
        }
        sort(v.begin(),v.end());
        
        int ans=0;
        vector<bool> visited(n,false);
        
        for(int i=0;i<n;i++){
            if(v[i].second == i || visited[i]==true ){
                continue;
            }
            
            int cycleSize=0;
            int j=i;
            
            while(visited[j]==false){
                visited[j]=true;
                j=v[j].second;
                cycleSize++;
            }
            if(cycleSize>1){
                ans+=cycleSize-1;
            }
        }
        
        return ans;
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
        cout << obj.minSwaps(arr) << endl;
    }
}

// } Driver Code Ends