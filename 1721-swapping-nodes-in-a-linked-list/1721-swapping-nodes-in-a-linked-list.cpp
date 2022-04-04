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
        ListNode *front=head,*last=head,*tail=head;
        for(int i=0;i<k-1;i++){
            tail=tail->next;
            front=front->next;
        }
        while(tail->next!=nullptr){
            tail=tail->next;
            last=last->next;
        }
        swap(last->val,front->val);
        return head;
    }
};