/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        ListNode* temp = head;
    
    // hashmap to store all visited nodes
    unordered_map<ListNode*, int> mp;
    
    // Traverse the list using temp
    while(temp!=NULL){
        // check if temp has been encountered again
        if(mp.count(temp)!=0){
            // A loop is detected hence return temp
            return temp;
        }
        // store temp as visited
        mp[temp] = 1;
        // iterate through the list
        temp = temp->next;
    }

    // If no loop is detected, return nullptr
    return nullptr; 
    }
};