// { Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
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
}

Node* findIntersection(Node* head1, Node* head2);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Node* result = findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}
// } Driver Code Ends


/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

Node* findIntersection(Node* head1, Node* head2)
{
    Node *ans=nullptr, *ptr1=head1, *ptr2=head2;
    while(1){
        if(ptr1->data<ptr2->data){
            if(ptr1->next)
                ptr1=ptr1->next;
            else break;
        }else if(ptr1->data>ptr2->data){
            if(ptr2->next)
                ptr2=ptr2->next;
            else break;
        }else {
            Node *tmp = new Node(ptr2->data);
            tmp->next=ans;
            ans=tmp;
            if(ptr1->next)
                ptr1=ptr1->next;
            else break;
            if(ptr2->next)
                ptr2=ptr2->next;
            else break;
        }
    }
    ptr1=ans;ptr2=nullptr;
    while(ptr1){
        Node *tmp=ptr1->next;
        ptr1->next=ptr2;
        ptr2=ptr1;
        ptr1=tmp;
    }
    return ptr2;
}