#include <iostream>
#include <stdexcept>

template<typename T>
class Queue{
    private:
        T* data;
        int capacity;
        int rear_idx;
        int front_idx;
    public:
        Queue(const int& size): capacity(size){
            data = new T[size];
            front_idx = rear_idx = 0;
        }
        ~Queue(){
            std::cout<<"Destructor called"<<std::endl;
            delete[] data;
        }
        void push(const T& value);
        T front();
        void pop();
        bool isEmpty() const;
        bool isFull() const;
};

template<typename T>
bool Queue<T>::isFull() const{
    return (rear_idx == capacity);
}

template<typename T>
bool Queue<T>::isEmpty() const{
    return (front_idx == rear_idx);
}

template<typename T>
void Queue<T>::pop(){

    if(isEmpty()){
        std::cerr<<"Queue is empty"<<std::endl;
        return;
    }
    for(int i = 0; i < rear_idx; i++){
        data[i] = data[i+1];
    }
    --rear_idx;
}

template<typename T>
T Queue<T>::front(){

    if(isEmpty()){
        std::cerr<<"Queue is empty";
        return T();
    }
    return data[front_idx];
}

template<typename T>
void Queue<T>::push(const T& value){
    if(isFull()){
        std::cerr<<"Queue is full"<<std::endl;
        return;
    }
    data[rear_idx++] = value;
}

int main(){

    Queue<int>* q = new Queue<int>(5);
    std::cout<<"is Empty?: "<<q->isEmpty()<<std::endl;
    q->pop();
    q->push(1);
    q->push(2);
    q->push(3);
    q->push(4);
    q->push(5);
    q->push(7);
    std::cout<<"is Full?: "<<q->isFull()<<std::endl;
    std::cout<<q->front()<<std::endl;
    q->pop();
    std::cout<<"is Full?: "<<q->isFull()<<std::endl;
    std::cout<<q->front()<<std::endl;

    delete q;
    return 0;
}