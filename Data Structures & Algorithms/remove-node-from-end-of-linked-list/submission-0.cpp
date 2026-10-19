// 2 pointers with a gap of n, starting from dummy O(n) time, O(1) space
// both pointers move until fast is the last node, slow before the node to remove
// return dummy.next, not the head: if the first node removed, head still points to it
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode dummy;
        dummy.next = head;
        ListNode* slow = &dummy;
        ListNode* fast = &dummy;

        // fast forward by n
        for(int i = 0; i < n; i++){
            fast = fast->next;
        }

        // iterate thru the linkedlist
        while(fast->next != nullptr){
            slow = slow->next;
            fast = fast->next;
        }

        // skip the middle
        slow->next = slow->next->next;

        return dummy.next;
    }
};
