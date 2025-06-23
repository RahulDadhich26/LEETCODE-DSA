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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p = nullptr;
        ListNode* ptr = head;
        while(ptr != nullptr){
            bool flag = false;
            ListNode* nextptr = ptr->next;
            while(nextptr != nullptr && ptr->val == nextptr->val){
             nextptr = nextptr->next;
             flag = true;
            }
            if(flag == true){
               if(p == nullptr){
                head = nextptr;
               }
               else{
                p->next = nextptr;
               }
           }
           else{
             p = ptr;
           }
            ptr = nextptr;
        }
        return head;
    }
};