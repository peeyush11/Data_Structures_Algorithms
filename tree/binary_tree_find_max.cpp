#include <iostream>
#include <queue>

struct Node{
    int data_;
    Node* left_;
    Node* right_;

    Node(int data) : data_(data), left_(nullptr), right_(nullptr){}
    ~Node(){}
};

int findMax(Node* temp){

    int root_val, left, right, max = -1;

    if(temp != nullptr){

        root_val = temp->data_;
        left = findMax(temp->left_);
        right = findMax(temp->right_);

        if(left > right)
            max = left;
        else
            max = right;
        
        if(root_val > max)
            max = root_val;
    }

    return max;
}

int main(){

    Node* root = new Node(10);
    root->left_ = new Node(8);
    root->right_ = new Node(12);
    root->left_->left_ = new Node(6);
    root->left_->right_ = new Node(17);
    root->right_->left_ = new Node(5);
    root->right_->right_ = new Node(15);


    int max_val = findMax(root);
    
    std::cout<<"max value in binary tree: "<< max_val<<std::endl;
    return 0;
}