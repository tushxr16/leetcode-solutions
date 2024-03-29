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
    bool isPalindrome(ListNode* head) {
        string s;
        ListNode* ptr = head;
        while(ptr){
            s.push_back(ptr->val+'0');
            ptr = ptr->next;
        }
        int n = s.size();
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-1-i]){
                return false;
            }
        }
        return true;
    }
};