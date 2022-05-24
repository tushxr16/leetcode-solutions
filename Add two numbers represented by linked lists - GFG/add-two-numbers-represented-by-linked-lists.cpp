// { Driver Code Starts
// driver

#include <bits/stdc++.h>
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

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
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

class Solution
{
    public:
    struct Node* reverse(struct Node* head){
        if(head==nullptr)return head;
        Node *prev=nullptr,*curr=head;
        while(curr!=nullptr){
            Node *tmp = curr->next;
            curr->next=prev;
            prev=curr;
            curr=tmp;
        }
        return prev;
    }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        first = reverse(first);
        second = reverse(second);
        Node *third = nullptr;
        Node *ptr1=first, *ptr2=second;
        int carry=0;
        while(ptr1!=nullptr && ptr2!=nullptr){
            int push = carry + (ptr1->data + ptr2->data);
            Node *tmp = new Node(push%10);
            carry=push/10;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
            tmp->next=third;
            third=tmp;
        }
        while(ptr1!=nullptr){
            int push = carry + (ptr1->data);
            Node *tmp = new Node(push%10);
            carry=push/10;
            ptr1=ptr1->next;
            tmp->next=third;
            third=tmp;
        }
        while(ptr2!=nullptr){
            int push = carry + (ptr2->data);
            Node *tmp = new Node(push%10);
            carry=push/10;
            ptr2=ptr2->next;
            tmp->next=third;
            third=tmp;
        }
        if(carry!=0){
            Node *tmp = new Node(1);
            tmp->next=third;
            third=tmp;
        }
        return third;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends