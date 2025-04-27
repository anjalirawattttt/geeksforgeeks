//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    void rearrange(vector<int> &arr) {
        vector<int> positive;
        vector<int> negative;
        
        for(int i=0;i<arr.size();i++){
            if(arr[i]>=0){
                positive.push_back(arr[i]);
            }
            else{
                negative.push_back(arr[i]);
            }
        }
        
        
        int posIndex=0,negIndex=0,i=0;
        
        while(posIndex<positive.size() && negIndex<negative.size()){
            if(i%2==0){
                arr[i++]=positive[posIndex++];
            }
            else{
                arr[i++]=negative[negIndex++];
                
            }
        }
        while(posIndex<positive.size()){
            arr[i++]=positive[posIndex++];
        }
        while(negIndex<negative.size()){
            arr[i++]=negative[negIndex++];
        }
        
        
       
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
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends