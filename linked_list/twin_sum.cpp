#include <bits/stdc++.h>

struct ListNode{
    int data;
    ListNode* next;

    ListNode(int x): data(x), next(nullptr){}

    ~ListNode(){
        delete next;
    }

};

void push(ListNode*&head, const int& val){

    if(head == nullptr){
        head = new ListNode(val);
    }
    else{
        ListNode* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }

        temp->next = new ListNode(val);
    }
}

void PrintList(ListNode* head){
    while(head != NULL){
        std::cout<<head->data<<"\t";
        head = head->next;
    }

    std::cout<<std::endl;
}

ListNode* ReverseList(ListNode* head){
    ListNode* prev = NULL;
    ListNode* current = head;
    ListNode* next;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}


int TwinSum_Method1(ListNode* head){
    //find the m iddle of the list, list is always of even size
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev;

    while(fast && fast->next){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    //At this point fast is at the last node and slow is at the mid node.
    //Now reverse the list from mid to end and get new head for the reversed list
    //which is the end of the list
    prev->next = NULL;
    ListNode* new_head = ReverseList(slow);

    int max_sum = 0;
    while(head && new_head){
        int sum = head->data + new_head->data;
        if(sum > max_sum) max_sum = sum;
        head = head->next;
        new_head = new_head->next;
    }

    return max_sum;
}

int TwinSum_Method2(ListNode* head){

    std::stack<int> st;
    ListNode* current = head;

    while(current != NULL){
        st.push(current->data);
        current = current->next;
    }
    current = head;
    int max_sum = 0;
    int sum;
    while(current != NULL && !st.empty()){
        sum = current->data + st.top();
        if(sum > max_sum) max_sum = sum;
        st.pop();
        current = current->next;
    }

    return max_sum;
}

int TwinSum_Method3(ListNode* head){

    ListNode* slow = head;
    ListNode* fast = head;
    std::stack<int> st;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    while(slow){
        st.push(slow->data);
        slow = slow->next;
    }

    ListNode* current = head;
    int max_sum = 0;
    while(!st.empty()){
        int sum = current->data + st.top();
        if(sum > max_sum) max_sum = sum;
        st.pop();
        current = current->next;
    }

    return max_sum;
}
int main(){

    ListNode* head = NULL;
    push(head, 5);
    push(head, 4);
    push(head, 2);
    push(head, 1);
    // push(head, 5);
    // push(head, 6);

    PrintList(head);
    // int max = TwinSum_Method1(head);
    int max1 = TwinSum_Method2(head);
    int max2 = TwinSum_Method3(head);
    // std::cout<<"Max twin sum: "<< max<<std::endl;
    std::cout<<"Max twin sum: "<< max1<<std::endl;
    std::cout<<"Max twin sum: "<< max2<<std::endl;
    return 0;
}