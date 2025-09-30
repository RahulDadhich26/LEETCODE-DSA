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
    int count = 0;
    ListNode* temp = head;

    // Count the total number of nodes
    while (temp) {
        count++;
        temp = temp->next;
    }

    // If the head is to be removed
    if (count == n) {
        ListNode* newHead = head->next;
        delete head;
        return newHead;
    }

    // Go to the (count - n - 1)th node
    temp = head;
    for (int i = 1; i < count - n; i++) {
        temp = temp->next;
    }

    // Remove the nth node from end
    ListNode* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;

    return head;
    }
};