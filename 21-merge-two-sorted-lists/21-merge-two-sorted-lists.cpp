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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *ptr1 = list1, *ptr2 = list2;
        ListNode *ans = nullptr;
        
        while(ptr1 && ptr2){
            int val;
            if(ptr1->val>ptr2->val){
                val = ptr2->val;
                ptr2 = ptr2->next;
            }else{
                val = ptr1->val;
                ptr1 = ptr1->next;
            }
            ListNode *temp = new ListNode(val);
            temp->next = ans;
            ans = temp;
        }
        while(ptr1){
            int val = ptr1->val;
            ptr1 = ptr1->next;
            ListNode *temp = new ListNode(val);
            temp->next = ans;
            ans = temp;
        }
        while(ptr2){
            int val = ptr2->val;
            ptr2 = ptr2->next;
            ListNode *temp = new ListNode(val);
            temp->next = ans;
            ans = temp;
        }
        ptr1 = nullptr, ptr2 = ans;
        while(ptr2){
            ListNode *temp = ptr2->next;
            ptr2->next = ptr1;
            ptr1 = ptr2;
            ptr2 = temp;
        }
        return ptr1;
    }
};