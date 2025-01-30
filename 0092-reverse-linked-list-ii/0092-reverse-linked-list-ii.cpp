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
        if (!head || left == right) {
        return head;
    }

    // Create a dummy node to handle cases where left = 1
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;

    // Move prev to the node just before the left position
    for (int i = 1; i < left; ++i) {
        prev = prev->next;
    }

    // Initialize pointers for reversing the sublist
    ListNode* curr = prev->next;
    ListNode* nextNode = nullptr;

    // Reverse the sublist
    for (int i = left; i < right; ++i) {
        nextNode = curr->next;
        curr->next = nextNode->next;
        nextNode->next = prev->next;
        prev->next = nextNode;
    }

    // Return the modified list
    ListNode* newHead = dummy->next;
    delete dummy; // Free the dummy node to avoid memory leaks
    return newHead;
    }
};