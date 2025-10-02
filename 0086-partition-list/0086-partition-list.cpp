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
    ListNode* partition(ListNode* head, int x) {
        if (!head) return nullptr;

        // Dummy heads for two lists
        ListNode beforeDummy(0), afterDummy(0);
        ListNode* before = &beforeDummy;
        ListNode* after = &afterDummy;

        // Traverse original list
        while (head) {
            if (head->val < x) {
                before->next = head;   // add to 'before' list
                before = before->next;
            } else {
                after->next = head;    // add to 'after' list
                after = after->next;
            }
            head = head->next;
        }

        // Break cycle in case of dangling nodes
        after->next = nullptr;

        // Merge the two lists
        before->next = afterDummy.next;

        return beforeDummy.next;
    }
};