/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *newHead=head,*tail=head;
        int n=1;
        if(head==NULL)return head;
        while(tail->next!=NULL){
            tail=tail->next;
            n++;
        }
        k=k%n;
        if(k==0)return head;
        for(int i=0;i<n-k-1;i++)newHead=newHead->next;
        tail->next=head;
        head=newHead->next;
        newHead->next=NULL;
        return head;
    }
};