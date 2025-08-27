class Solution {
  public:
    int getXor(vector<int>& nums, int a, int b) {
        int ans=0;
        for(int i=a;i<=b;i++)ans=ans^nums[i];
        return ans;
    }
};