/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        HashSet<ListNode> seen = new HashSet<>();
        ListNode fast = head;
        while(fast!=null){
            if(seen.contains(fast)){
                return fast;
            }
            seen.add(fast);
            fast = fast.next;
        }
        return null;
    }
}