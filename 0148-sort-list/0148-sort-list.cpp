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
    private:
    ListNode* findMiddle(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    // Merge two sorted linked lists
    ListNode* merge(ListNode* left, ListNode* right) {
        if (!left) return right;
        if (!right) return left;
        
        if (left->val <= right->val) {
            left->next = merge(left->next, right);
            return left;
        } else {
            right->next = merge(left, right->next);
            return right;
        }
    }
    
    // Main recursive merge sort function
    ListNode* mergeSort(ListNode* head) {
        // Base case
        if (!head || !head->next) return head;
        
        // Find middle and split list
        ListNode* middle = findMiddle(head);
        ListNode* rightHalf = middle->next;
        middle->next = nullptr;
        
        // Recursively sort both halves
        ListNode* left = mergeSort(head);
        ListNode* right = mergeSort(rightHalf);
        
        // Merge sorted halves
        return merge(left, right);
    }
public:
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};