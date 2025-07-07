class Node {
  public:
    int val;
    Node* next;
    // Constructor of Node
    Node(int x): val(x), next(nullptr) {}
	// Above code is equivalent to the below code
	// Node(int x) { val=x; next=nullptr;}
};
class MyLinkedList {
public:
    Node* head;
    int size;
    MyLinkedList(): head(nullptr), size(0) {}
    int get(int index) {
        if(index < 0 || index >= size) return -1;
        Node *curr = head;
        for(int i=0;i<index;i++){
            curr = curr->next;
        }
        return curr->val;
    }
    void addAtHead(int val) {
        addAtIndex(0,val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size,val);
    }
    
    void addAtIndex(int index, int val) {
        if(index > size || index < 0) return;
        Node * curr = head;
        Node * newNode = new Node(val);

        if(index == 0){
            newNode->next = curr;
            head = newNode;
        }
        else{
            for(int i = 0 ; i< index-1;i++){
                curr = curr->next;
            }
            newNode->next = curr->next;
            curr->next = newNode;
        }
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index >= size || index < 0) return;

        if(index == 0){
            Node* nextNode = head->next;
           delete head;
           head = nextNode; 
        }
        else{
            Node *curr = head;
             for(int i=0;i<index-1;++i) {
                curr= curr->next;
            }
            Node* nextNode = curr->next->next;
            delete curr->next;
            curr->next = nextNode;
        }
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */