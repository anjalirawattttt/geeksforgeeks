class Solution {
  public:
    void insert(stack<int> &St,int x){
        if(St.empty()){
            St.push(x);
            return;
        } 
        int top=St.top();
        St.pop();
        insert(St,x);
        St.push(top);
    }
    void reverse(stack<int> &St) {
        if(St.empty())return;
        int top=St.top();
        St.pop();
        reverse(St);
        insert(St,top);
    }
};