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
    struct compare {
        bool operator()(ListNode *a, ListNode *b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      priority_queue<ListNode*, vector<ListNode*>, compare>pq;
        for(auto node : lists){
            if(node) pq.push(node);
        } 

        ListNode dummy;
        ListNode *tail = &dummy;

        while(!pq.empty()){
            ListNode *top = pq.top(); 
            pq.pop();
            tail->next = top;
            tail = tail->next;

            if(top->next) pq.push(top->next);
        }
        return dummy.next;
    }
};