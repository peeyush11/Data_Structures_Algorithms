#include <iostream>
#include <vector>

template<typename T>
class Stack{
    private: 
        std::vector<T> data;
        int capacity;

    public:
        Stack(const int& size);
        bool isEmpty() const;
        bool isFull() const;
        void push(const T& value);
        T top() const ;
        void pop();
        int size() const;    
};

template<typename T>
Stack<T>::Stack(const int& size){
    capacity = size;
    data.reserve(size);
}

template<typename T>
bool Stack<T>::isEmpty() const{
    
    return data.empty();
}

template<typename T>
bool Stack<T>::isFull() const{

    return (data.size() == capacity);
}

template<typename T>
void Stack<T>::push(const T& value){
    data.push_back(value);
}

template<typename T>
T Stack<T>::top() const{
    return data.back();
}   

template<typename T>
void Stack<T>::pop(){
    data.pop_back();
    
}

template<typename T>
int Stack<T>::size() const{
    return data.size();
}

int main(){

    Stack<int> st(5);

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.pop();
    int val = st.top();
    val = 2;
    std::cout<<st.top()<<std::endl;
    std::cout<<st.size()<<std::endl;

    Stack<char> st1(3);
    st1.push('a');
    std::cout<<st1.top()<<std::endl;
    return 0;
}