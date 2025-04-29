//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends

/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* reverse(Node* head){
        if(!head || head->next==NULL)return head;
        Node* prev=NULL;
        Node* curr=head;
        Node* next;
        
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        return prev;
    }
    
    int countNodes(Node* head){
        int count=0;
        Node* ptr=head;
        while(ptr!=NULL){
            ptr=ptr->next;
            count++;
        }
        return count;
    }
    
    Node* removeZeroes(Node* head){
        while(head->next!=NULL && head->data==0 ){
            head=head->next;
        }
        return head;
    }
    
    
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
        num1=removeZeroes(num1);
        num2=removeZeroes(num2);
        int l1=countNodes(num1);
        int l2=countNodes(num2);
        if(l1<l2)return addTwoLists(num2,num1);
        
        int carry=0; 
        num1=reverse(num1);
        num2=reverse(num2);
        Node* res=num1;
        while(num2!=NULL || carry!=0){
            num1->data+=carry;
            if(num2!=NULL){
                num1->data+=num2->data;
                num2=num2->next;
            }
            
            carry=num1->data/10;
            num1->data=num1->data%10;
            if(num1->next==NULL && carry!=0){
                num1->next=new Node(0);
            }
            num1=num1->next;
        }
        
        return reverse(res);
        
        
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends