// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* reverse(Node* head){
        Node* curr=head, *prev=nullptr;
        while(curr!=nullptr){
            Node *tmp =curr->next;
            curr->next = prev;
            prev=curr;
            curr=tmp;
        }
        return prev;
    }
    Node* addOne(Node *head) 
    {
        if(head==nullptr)
            return head;
        head = reverse(head);
        int carry=1;
        Node *ptr=head, *prev;
        while(ptr!=nullptr){
            int sum = ptr->data + carry;
            carry=sum/10;
            ptr->data=sum%10;
            prev=ptr;
            ptr=ptr->next;
        }
        if(carry==1){
            Node *tmp = new Node(1);
            prev->next=tmp;
        }
        return reverse(head);
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends