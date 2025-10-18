vector<int> Smallestonleft(int arr[], int n) {
    vector<int> ans(n);
    set<int> s;
    for(int i=0;i<n;i++){
        s.insert(arr[i]);
        auto it=s.lower_bound(arr[i]);
        if(it==s.begin()){
            ans[i]=-1;    
        }
        else{
            ans[i]=*(prev(it));
        }
    }
    return ans;
    
}