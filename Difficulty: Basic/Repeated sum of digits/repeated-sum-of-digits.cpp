//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution {
  public:
    int sumOfDigits(int N){
        int sum=0;
        int digit;
        while(N>0){
            digit=N%10;
            sum+=digit;
            N=N/10;
        }
        return sum;
    }
    
    int repeatedSumOfDigits(int N) {
        
        while(N >= 10){
            N=sumOfDigits(N);
        }
        return N;
        
    }
};



//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.repeatedSumOfDigits(N) << endl;
    
cout << "~" << "\n";
}
    return 0; 
} 
// } Driver Code Ends