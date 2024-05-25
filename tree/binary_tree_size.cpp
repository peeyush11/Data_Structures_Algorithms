#include <iostream>
#include <queue>

struct Node{
    int data_;
    Node* left_;
    Node* right_;

    Node(int data) : data_(data), left_(nullptr), right_(nullptr){}
    ~Node(){}
};

int SizeOfTree(Node* root){

    if(root == nullptr)
        return 0;

    return (SizeOfTree(root->left_) + 1 + SizeOfTree(root->right_));
}

int main(){

    Node* root = new Node(10);
    root->left_ = new Node(8);
    root->right_ = new Node(12);
    root->left_->left_ = new Node(6);
    root->left_->right_ = new Node(17);
    root->right_->left_ = new Node(5);
    root->right_->right_ = new Node(15);

    int tree_size = SizeOfTree(root);
    
    std::cout<<"Size of tree:  "<<tree_size<<std::endl;
    
    return 0;
}