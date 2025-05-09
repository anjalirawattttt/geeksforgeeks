//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(struct Node *head) {
    struct Node *temp = head;
    if (head == NULL) {
        cout << "NULL";
    }
    while (temp != NULL) {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << '\n';
}


// } Driver Code Ends

/*
structure of the node of the linked list is
struct Node
{
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/
// Function to merge two linked lists
class Solution {
  public:
    vector<Node *> mergeList(struct Node **head1, struct Node **head2) {
        // Code Here
        if(head1==NULL || head2==NULL)return {head1,head2};
        Node* curr1=*head1;
        Node* curr2=*head2;
        while(curr1!=NULL && curr2!=NULL){
            Node* ptr1=curr1->next;
            Node* ptr2=curr2->next;
            curr1->next=curr2;
            curr2->next=ptr1;
            curr1=ptr1;
            curr2=ptr2;
        }
        
        return {*head1,curr2};
    }
};


//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n1, n2, tmp;
        Node *head1 = nullptr, *tail1 = nullptr;
        Node *head2 = nullptr, *tail2 = nullptr;
        string input1, input2;

        getline(cin, input1); // Read the entire line for the LL1 elements
        stringstream ss1(input1);
        while (ss1 >> tmp) {
            Node *new_node = new Node(tmp);
            if (head1 == nullptr) {
                head1 = new_node;
                tail1 = new_node;
            } else {
                tail1->next = new_node;
                tail1 = new_node;
            }
        }

        getline(cin, input2); // Read the entire line for the LL2 elements
        stringstream ss2(input2);
        while (ss2 >> tmp) {
            Node *new_node = new Node(tmp);
            if (head2 == nullptr) {
                head2 = new_node;
                tail2 = new_node;
            } else {
                tail2->next = new_node;
                tail2 = new_node;
            }
        }

        Solution obj;
        vector<Node *> new_heads = obj.mergeList(&head1, &head2);
        printList(new_heads[0]);
        printList(new_heads[1]);
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends