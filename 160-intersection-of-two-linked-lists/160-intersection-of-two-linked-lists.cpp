/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int a = 0, b = 0, c = 0;
        ListNode *ptr1 = headA, *ptr2 = headB;
        
        while(ptr1){
            ptr1 = ptr1->next;
            a++;
        }
        
        while(ptr2){
            ptr2 = ptr2->next;
            b++;
        }
        
        ptr1 = headA, ptr2 = headB;
        
        while(b>a){
            ptr2 = ptr2->next;
            b--;
        }
        while(a>b){
            ptr1 = ptr1->next;
            a--;
        }
        while(ptr1!=ptr2){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return ptr1;
    }
};