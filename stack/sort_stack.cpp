#include <iostream>
#include <stack>

auto sortStack(std::stack<int>* input){

    std::stack<int>* tempStack = new std::stack<int>();
    int current;
    while(!input->empty()){
        current = input->top();
        input->pop();
        while(!tempStack->empty() && tempStack->top() > current){
                input->push(tempStack->top());
                tempStack->pop();
            }
        tempStack->push(current);
    }

    return tempStack;
}

int main(){

    std::stack<int>* input = new std::stack<int>();
    input->push(11);
    input->push(2);
    input->push(32);
    input->push(3);
    input->push(41);

    auto st = sortStack(input);

    std::cout<<st->top();
    return 0;
}