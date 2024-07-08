#include <iostream>

template<typename U>
struct ListNode{
    U data;
    ListNode* next;

    ListNode(const U& value): data(value), next(nullptr){}

    ~ListNode(){
        std::cout<<"ListNode destructor called"<<std::endl;
    }
};

template<typename T>
class LinkedList{
    private: 
        ListNode<T>* head;
    
    public:
        LinkedList(): head(nullptr){}
        ~LinkedList(){

            std::cout<<"LinkedList destructor called"<<std::endl;

            ListNode<T>* current = head;
            while(current != NULL){
                ListNode<T>* temp = current->next;
                delete current;
                current = temp;
            }

            head = NULL;
        }

        void push(const T& value);

        void printList() const;
};

template<typename T>
void LinkedList<T>::printList() const{
    ListNode<T>* current = head;
    while(current != NULL){
        std::cout<<current->data<<"\t";
        current = current->next;
    }
    std::cout<<std::endl;
}

template<typename T>
void LinkedList<T>::push(const T& value){

    ListNode<T>* newNode = new ListNode<T>(value);

    if(!head){    
        head = newNode;
    }
    else{
        ListNode<T>* temp = head;

        while(temp->next != NULL){
            temp = temp->next;
        }

        temp->next = newNode; 
    }
}


int main(){

    LinkedList<int>* l1 = new LinkedList<int>();

    l1->push(1);
    l1->push(100);
    l1->push(200);
    l1->push(20);
    l1->push(33);
    l1->printList();
    delete l1;
    return 0;
}