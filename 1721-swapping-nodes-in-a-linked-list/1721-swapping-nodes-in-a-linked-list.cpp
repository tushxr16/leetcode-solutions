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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *ptr1=head, *ptr2=head, *ptr3=head;
        for(int i=0;i<k;i++)ptr2=ptr2->next;
        while(ptr2!=NULL){ptr2=ptr2->next;ptr1=ptr1->next;}
        for(int i=0;i<k-1;i++)ptr3=ptr3->next;
        swap(ptr3->val,ptr1->val);
        return head;
    }
};