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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int currVal=0,carry=0;string s="";
        ListNode* ans = new ListNode();
        ans=NULL;
        while(l1!=NULL || l2!=NULL){
            currVal+=carry;
            
            if(l1!=NULL){currVal+=l1->val;l1=l1->next;}
            if(l2!=NULL){currVal+=l2->val;l2=l2->next;}
            
            s.push_back(currVal%10 +48);
            carry = currVal/10;
            currVal=0;
        }
        if(carry!=0){
            ListNode* tmp = new ListNode();
            tmp->val = carry;
            tmp->next = ans;
            ans = tmp;
        }
        for(int i=0;i<s.size();i++){
            ListNode* tmp = new ListNode();
            tmp->val = s[s.size()-1-i]-48;
            tmp->next = ans;
            ans = tmp;
        }
        return ans;
    }
};