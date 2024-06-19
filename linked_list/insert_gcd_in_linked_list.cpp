#include <bits/stdc++.h>

struct Node{
    int data;
    Node* next;

    Node(int x): data(x), next(nullptr){}

    ~Node(){
        delete next;
    }
};

int ComputeGcd_Euclidean_method(int num1, int num2){
    if(num1 == 0) return num2;

    return ComputeGcd_Euclidean_method(num2%num1, num1);
}

int ComputeGcd(const int& num1, const int& num2){

    int num = std::max(num1, num2);
    while(num){
        std::cout<<num<<std::endl;
        if(num1 % num == 0 &&  num2 % num == 0) break;
        num--;
    }

    return num;
}
int main(){

    Node* head = new Node(18);
    head->next = new Node(6);

    
    std::cout<<ComputeGcd_Euclidean_method(18, 6);
    return 0;
}