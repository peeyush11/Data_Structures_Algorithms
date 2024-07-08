#include <iostream>
#include <stdexcept>
#include <memory>

template<typename T>
class Stack{
    private:
        T* data;
        int capacity;
        int top_idx = -1;
    public:
        Stack(const int& size);
        ~Stack();
        bool isEmpty() const;
        bool isFull() const;
        void push(const T& value);
        T top() const;
        void pop();
};      

template<typename T>
Stack<T>::Stack(const int& size){
    capacity = size;
    data = new T[size];
}

template<typename T>
Stack<T>::~Stack(){
    delete[] data;
    std::cout<<"Stack destructor called"<<std::endl;
}

template<typename T>
bool Stack<T>::isEmpty() const{
    return (top_idx == -1);
}

template<typename T>
bool Stack<T>::isFull() const{

    return (top_idx == capacity-1);
}
template<typename T>
void Stack<T>::push(const T& value){
    if(isFull()){
        throw std::overflow_error("Stack is full");
    }

    data[++top_idx] = value;   
}

template<typename T>
T Stack<T>::top() const{

    if(isEmpty()){
        throw std::underflow_error("Stack is empty");
    }

    return data[top_idx];
}
template<typename T>
void Stack<T>::pop() {
    
    if(isEmpty()){
        throw std::underflow_error("Stack is empty");
    }
    
    // delete data[top_idx];
    top_idx--;
}

int main(){

    // stack object creation on stack memory
    Stack<int> st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    std::cout<<st.top()<<std::endl;
    st.pop();
    std::cout<<st.top()<<std::endl;
   
    // Stack object creation on heap using new
    Stack<int>* st1 = new Stack<int>(5);
    st1->push(10);
    st1->push(20);
    std::cout<<st1->top()<<std::endl;
    st1->pop();
    std::cout<<st1->top()<<std::endl;

    // Stack object creation on heap using smart pointer
    auto st2 = std::make_unique<Stack<int>>(5);
    // getting raw pointer from smart pointer.
    Stack<int>* temp = st2.get();
    st2->push(100);
    st2->push(200);
    st2->push(300);
    std::cout<<st2->top()<<std::endl;
    std::cout<<temp->top()<<std::endl;
    st2->pop();
    std::cout<<st2->top()<<std::endl;

    // the destructor will be called three times
    // 1. for stack object st, since it is on stack, 
    // destructor will be called automatically when it goes out of scope.
    // 2. delete st1, will call destructor since st1 was created using new.
    // 3. st2 is created using smart pointer, destructor will be automatically
    //    called when it goes out of scope.
    delete st1;
    return 0;
}