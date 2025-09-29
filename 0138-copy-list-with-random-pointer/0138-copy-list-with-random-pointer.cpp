/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
         if (!head) return nullptr;
        
        unordered_map<Node*, Node*> oldToNew;

        // Pehla pass: clone nodes & map original -> copy
        Node* curr = head;
        while (curr) {
            oldToNew[curr] = new Node(curr->val);
            curr = curr->next;
        }

        // Dusra pass: set next and random pointers
        curr = head;
        while (curr) {
            oldToNew[curr]->next = oldToNew[curr->next];
            oldToNew[curr]->random = oldToNew[curr->random];
            curr = curr->next;
        }

        return oldToNew[head];
    }
};