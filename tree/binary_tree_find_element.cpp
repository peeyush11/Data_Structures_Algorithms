#include <iostream>
#include <queue>

struct Node{
    int data_;
    Node* left_;
    Node* right_;

    Node(int data) : data_(data), left_(nullptr), right_(nullptr){}
    ~Node(){}
};

bool findElement(Node* root, int& val){
    
    int temp;
    if(root == nullptr)
        return 0;
    
    if(root->data_ == val)
        return 1;

    temp =  findElement(root->left_, val);

    if(temp != 0)
        return temp;
    else
        return findElement(root->right_, val);
}

bool findElement_2(Node* root, int& val){
    if(root == nullptr) return false;
    if(root->data_ == val) return true;

    return findElement_2(root->left_, val) || findElement_2(root->right_, val);
}

int main(){

    Node* root = new Node(10);
    root->left_ = new Node(8);
    root->right_ = new Node(12);
    root->left_->left_ = new Node(6);
    root->left_->right_ = new Node(17);
    root->right_->left_ = new Node(5);
    root->right_->right_ = new Node(15);

    int val = 15;
    bool flag = findElement(root, val);
    bool flag2 = findElement_2(root, val);
    
    if(flag)
        std::cout<<"Method 1: Value found in tree "<<std::endl;
    else
        std::cout<<"Method 1: Value not found in tree"<<std::endl;

    if(flag2)
        std::cout<<"Method 2: Value found in tree "<<std::endl;
    else
        std::cout<<"Method 2: Value not found in tree"<<std::endl;

    return 0;
}