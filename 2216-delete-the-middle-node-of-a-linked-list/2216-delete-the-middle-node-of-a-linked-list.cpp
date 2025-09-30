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
    ListNode* deleteMiddle(ListNode* head) {
    if (!head || !head->next) return nullptr;
    int count = 0;
    ListNode* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    int mid = count / 2; 
    temp = head;
    for (int i = 1; i < mid; i++) {
        temp = temp->next;
    }
    ListNode* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;

    return head;
    }
};