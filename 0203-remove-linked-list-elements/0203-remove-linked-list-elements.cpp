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
    ListNode* removeElements(ListNode* head, int target) {
        if(head == nullptr) return head;
        ListNode *temp = head;
        while(temp->next != nullptr){
            if(temp->next->val == target){
                temp->next = temp->next->next;
            }
            else{
                temp = temp->next;
            }
        }
        if(head->val == target) return head->next;
        return head;
    }
};