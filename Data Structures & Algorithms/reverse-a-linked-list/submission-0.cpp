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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;

        while(cur != nullptr){
            // tmp next node 
            ListNode* next = cur->next;
            // reverse cur->next to prev
            cur->next = prev;
            // update prev
            prev = cur;
            // update cur
            cur = next;
        }
        return prev;
    }
};
