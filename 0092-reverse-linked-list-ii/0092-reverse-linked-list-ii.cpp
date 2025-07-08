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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;
    
    // Create dummy for edge cases
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    
    // Find the node just before the reversal range
    ListNode* prevNode = dummy;
    for (int i = 1; i < left; i++) {
        prevNode = prevNode->next;
    }
    
    // Start reversing from position left
    ListNode* current = prevNode->next;
    
    // Reverse (right - left) times
    for (int i = 0; i < right - left; i++) {
        ListNode* nodeToMove = current->next;    // Node to move
        current->next = nodeToMove->next;        // Skip the node to move
        nodeToMove->next = prevNode->next;       // Point to beginning of reversed part
        prevNode->next = nodeToMove;             // Make it new first node
    }
    
    return dummy->next;
    }
};