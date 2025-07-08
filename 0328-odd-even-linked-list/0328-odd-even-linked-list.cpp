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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return NULL;

        ListNode* odd = head;
        ListNode* even = head->next;

        ListNode* temp_odd = odd;
        ListNode* temp_even= even;

        while(temp_odd->next != NULL && temp_even->next != NULL)
        {
            temp_odd->next = temp_odd->next->next;
            temp_even->next = temp_even->next->next;

            temp_odd = temp_odd->next;
            temp_even = temp_even->next;
        }
        temp_odd->next = even;

        return head;
    }
};