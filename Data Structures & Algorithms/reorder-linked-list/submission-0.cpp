// Reorder in 3 steps, O(n) time, O(1) space:
// 1. Fast/ slow pointers find the end of the first half; slow->next = null
// 2. Reverse second half in place
// 3. Relink the list, saving the next pointers before relinking
// second half always shorter than the first so stop when it runs out

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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        // move slow into the mid
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse the back half
        ListNode* prev = nullptr;
        ListNode* cur = slow->next;
        slow->next = nullptr; // cutting the first half

        while(cur != nullptr){
            ListNode* next_node = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next_node;
        }

        // from the new linkedlist using prev and head
        while(prev != nullptr){
            ListNode* first = head->next;
            ListNode* second = prev->next;
            head->next = prev;
            prev->next = first;
            head = first;
            prev = second;
        }
    }
};
