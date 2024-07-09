#include <iostream>
#include <vector>

template <typename T>
class Queue{
    private:
        std::vector<T> data;
        int capacity;

    public:
         Queue(const int& size){
            capacity = size;
            data.reserve(size);
         }  

         ~Queue(){}

         void push(const T& value);
         T front() const;
         void pop();
         bool isEmpty() const;
         bool isFull() const;

};

template<typename T>
bool Queue<T>::isFull() const{
    return capacity == data.size();
}

template<typename T>
bool Queue<T>::isEmpty() const{
    return data.empty();
}

template <typename T>
void Queue<T>::push(const T& value){

    data.push_back(value);
}

template <typename T>
T Queue<T>::front() const{
    return data.front();
}

template <typename T>
void Queue<T>::pop(){
    data.erase(data.begin());
}

int main()
{
    Queue<int>* q = new Queue<int>(5);

    std::cout<<"is empty?: "<<q->isEmpty()<<std::endl;
    q->push(10);
    q->push(20);
    q->push(30);
    q->push(40);
    q->push(50);
    

    std::cout<<q->front()<<std::endl;
    q->pop();
    std::cout<<"is Full?: "<<q->isFull()<<std::endl;
    std::cout<<"is empty?: "<<q->isEmpty()<<std::endl;
    std::cout<<q->front()<<std::endl;
    return 0;
}