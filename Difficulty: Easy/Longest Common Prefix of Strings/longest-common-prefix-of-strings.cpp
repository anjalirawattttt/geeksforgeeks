// User function template for C++
class Solution {
  public:
    string longestCommonPrefix(vector<string> arr) {
        // your code here
        string str1=arr[0];
        for(int i=1;i<arr.size();i++){
            string str2=arr[i];
            int n1=str1.size(),n2=str2.size();
            int j=0;
            while(j<n1 && j<n2 && str1[j]==str2[j]){
                j++;
            }
            str1=str1.substr(0,j);
        }
        return str1;
    }
};