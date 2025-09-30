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
    ListNode* swapPairs(ListNode* head) {
         if (!head || !head->next) return head;

        // Step 1: First swap
        ListNode* newHead = head->next;
        ListNode* prev = nullptr;
        ListNode* curr = head;

        // Step 2: Traverse and swap in pairs
        while (curr && curr->next) {
            ListNode* nextPair = curr->next->next;
            ListNode* second = curr->next;

            // Swap
            second->next = curr;
            curr->next = nextPair;

            // Link previous pair with current swapped pair
            if (prev) prev->next = second;

            // Update prev and curr for next round
            prev = curr;
            curr = nextPair;
        }

        return newHead;
    }
};