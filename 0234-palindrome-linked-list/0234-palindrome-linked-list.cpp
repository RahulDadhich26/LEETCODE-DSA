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
          if(!head || !head->next) return true;

    ListNode *slow = head, *fast = head;
    ListNode *prev = nullptr, *next = nullptr;

    // Reverse first half while finding mid
    while(fast && fast->next) {
        fast = fast->next->next;

        next = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next;
    }

    // If odd number of nodes, skip middle node
    if(fast) slow = slow->next;

    // Compare both halves
    while(prev && slow) {
        if(prev->val != slow->val) return false;
        prev = prev->next;
        slow = slow->next;
    }

    return true;
    }
};