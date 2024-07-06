#include <bits/stdc++.h>

struct ListNode{
    int data;
    std::unique_ptr<ListNode> next;

    ListNode(int val): data(val), next(nullptr){}
};

class LinkedList{

    std::unique_ptr<ListNode> head;

    public:
    LinkedList(): head(nullptr){}

    ~LinkedList(){
        // smart pointer will take care of deleting the memory
        // But we have loop in the linked list.
        // the last node points to some other node in between the list
        // We have to handle this loop removal in destructor 
        // else we get segmentation error.    
        DetectAndRemoveLoop();
    };

    void append(const int& val);

    void printList() const;

    void createLoopAtPos(const int& pos);

    void DetectAndRemoveLoop();
};

void LinkedList::append(const int& val){
        auto newNode = std::make_unique<ListNode>(val);

        if(!head){
            head = std::move(newNode);
        }
        else{
            ListNode* current = head.get();

            while(current->next){
                current = current->next.get();
            }
            current->next = std::move(newNode);
        }
}

void LinkedList::printList() const{

    ListNode* current = head.get();

    while(current != NULL){
        std::cout<<current->data<<"\t";
        current = current->next.get();
    }
    std::cout<<std::endl;
}

void LinkedList::createLoopAtPos(const int& pos){
    if(!head) return;

    ListNode* current = head.get();
    ListNode* loop_node = nullptr;
    int idx = 1;
    // Traverse the list to find the node at position 'pos'
    while (current->next && idx < pos) {
        if (idx == pos - 1) {
            loop_node = current;  // Found the node where the loop should start
        }
        current = current->next.get();
        idx++;
    }

    if (!loop_node) {
        std::cout << "Position " << pos << " not found in the list." << std::endl;
        return;
    }

    // Move 'current' to the last node
    while (current->next) {
        current = current->next.get();
    }

    // Set the next pointer of the last node to 'loop_node'
    current->next.reset(loop_node);
 

    std::cout << "Loop created from tail to node at position " << pos << std::endl;

}

void LinkedList::DetectAndRemoveLoop(){

    ListNode* slow = head.get();
    ListNode* fast = head.get();

    int flag = 0;

    while(fast && fast->next.get()){
        slow = slow->next.get();
        fast = fast->next.get()->next.get();

        if(slow == fast){
            flag = 1;
            break;
        } 
    }
    
    if(flag){
        slow = head.get();
       

        while(slow != fast){
            slow = slow->next.get();
            fast = fast->next.get();
        }

        while(fast->next.get() != slow){
            fast = fast->next.get();
        }
        // use release to relinquish ownership without deleting the node
        // without release(), reset will also delete the node
        // this will lead to double delete error as there is one node
        // still existing which points to it.
        fast->next.release();
        // reset sets the next to nullptr
        fast->next.reset(nullptr);
    }

}
int main(){

    LinkedList list;

    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    list.append(6);
    list.append(7);
    list.append(8);
    list.append(9);
    list.append(10);
    list.append(11);
    list.append(12);
    list.append(13);
    list.append(14);
    list.append(15);

    list.printList();
    list.createLoopAtPos(6);
    // list.DetectAndRemoveLoop();
    return 0;

}