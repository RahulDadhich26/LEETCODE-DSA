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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
          stack<int> s1, s2;

        // Push all nodes of l1 to stack
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }

        // Push all nodes of l2 to stack
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        ListNode* head = nullptr;
        int carry = 0;

        // Process stacks
        while (!s1.empty() || !s2.empty() || carry != 0) {
            int a = (!s1.empty()) ? s1.top() : 0;
            int b = (!s2.empty()) ? s2.top() : 0;
            if (!s1.empty()) s1.pop();
            if (!s2.empty()) s2.pop();

            int sum = a + b + carry;
            int digit = sum % 10;
            carry = sum / 10;

            // Insert at front
            ListNode* newNode = new ListNode(digit);
            newNode->next = head;
            head = newNode;
        }

        return head;
    }
};