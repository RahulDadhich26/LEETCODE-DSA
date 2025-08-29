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
    ListNode* rotateRight(ListNode* head, int k) {
       if(!head || !head->next || k == 0) return head;
       // 1.	Find length of linked list.
       int length = 1;
       ListNode* tail = head;
       while(tail->next){
        tail = tail->next;
        length++;
       }
       // 2.	Connect tail to head → temporarily circular list banado.
       tail->next = head;
       // 3.	Break the circle at the right spot or find new head;
       k = k % length;
       	// steps_to_new_head = length - (k % length).
       int stepsToNewhead = length - k;
        //  Traverse that many steps → new head banega.
       ListNode* newTail = tail;
       while(stepsToNewhead--){
        newTail = newTail->next;
       }
       	// 4.	Cut the link just before new head → ye final rotated list.
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        return newHead;
    }
};