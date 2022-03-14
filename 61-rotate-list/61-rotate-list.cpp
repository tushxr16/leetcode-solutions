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
        if(head==nullptr)return head;
        ListNode* ptr = head, *ptr2 = head;int n=1;
        while(ptr->next!=nullptr){n++;ptr=ptr->next;}
        k=k%n;
        if(k==0)return head;
        ptr->next = head;
        for(int i=0;i<n-k-1;i++)ptr2=ptr2->next;
        head = ptr2->next;
        ptr2->next=nullptr;
        return head;
    }
};