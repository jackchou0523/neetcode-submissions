// Merge with a dummy head O(n + m) time, O(1) space
// tail always points to the last node of the result, nodes are relinked
// dummy is local, not new, so nothing to delete, return dummy.next
// <= takes from list1 when ties, keeping the merge stable
// when one list runs out, attach the rest of other

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
        ListNode dummy;
        ListNode* tail = &dummy;

        while(list1 != nullptr && list2 != nullptr){
            if(list1->val <= list2->val){
                tail->next = list1;
                list1 = list1->next;
            }
            else{
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        tail->next = (list1 == nullptr) ?  list2 : list1;


        return dummy.next;
    }
};
