/*The structure of the class is
class SortedStack{
public:
    stack<int> s;
    void sort();
};
*/

/* The below method sorts the stack s
you are required to complete the below method */
void insert(stack<int>& s,int x){
    if(s.empty() || s.top()<=x){
        s.push(x);
        return;
    }  
    int top=s.top();
    s.pop();
    insert(s,x);
    s.push(top);
}
void SortedStack ::sort() {
    if(s.empty())return;
    int top=s.top();
    s.pop();
    SortedStack::sort();
    insert(s,top);
}