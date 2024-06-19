#include <iostream>
#include <stack>
#include <algorithm>

struct Node{
    int data;
    Node* next;

    Node(int x) : data(x), next(nullptr) {}
    ~Node(){
        delete next;
    }
};

int getSize(Node* head){
    int count = 0;
    while (head != nullptr) {
        ++count;
        head = head->next;
    }
    return count;
}

Node* addition(Node* temp1, Node* temp2, int size1, int size2, int& carry) {
    if (temp1 == nullptr && temp2 == nullptr) return nullptr;
    
    int sum = 0;
    Node* newNode = new Node(0);

    if (size1 == size2) {
        newNode->next = addition(temp1->next, temp2->next, size1-1, size2-1, carry);
        sum = temp1->data + temp2->data + carry;
    } else {
        newNode->next = addition(temp1, temp2->next, size1, size2-1, carry);
        sum = temp2->data + carry;
    }
    
    carry = sum / 10;
    newNode->data = sum % 10;

    return newNode;
}

Node* addTwoLists(Node* head1, Node* head2) {
    int size1 = getSize(head1);
    int size2 = getSize(head2);
    int carry = 0;
    
    Node* result;
    if (size1 <= size2) {
        result = addition(head1, head2, size1, size2, carry);
    } else {
        result = addition(head2, head1, size2, size1, carry);
    }
    
    if (carry) {
        Node* newNode = new Node(carry);
        newNode->next = result;
        result = newNode;
    }

    return result;
}

void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << "\t";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head1 = new Node(4);
    head1->next = new Node(5);

    Node* head2 = new Node(3);
    head2->next = new Node(4);
    head2->next->next = new Node(5);

    Node* result = addTwoLists(head1, head2);
    printList(result);

    delete result; // This will delete all nodes because of the destructor in Node

    return 0;
}
