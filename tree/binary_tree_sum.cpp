#include <iostream>
#include <queue>

struct Node{
    int data_;
    Node* left_;
    Node* right_;

    Node(int data) : data_(data), left_(nullptr), right_(nullptr){}
    ~Node(){}
};

int TreeSumRecursive(Node* root){
    if(root == nullptr) return 0;

    return (root->data_ + TreeSumRecursive(root->left_) + TreeSumRecursive(root->right_));
}

int TreeSumIterative(Node* root){
    if(root == nullptr) return 0;

    Node* current;
    std::queue<Node*> q;
    q.push(root);

    int total_sum = 0;

    while(!q.empty()){
        current = q.front();
        total_sum += current->data_;
        q.pop();
        if(current->left_) q.push(current->left_);
        if(current->right_) q.push(current->right_);
    }

    return total_sum;
}

int main(){

    Node* root = new Node(1);
    root->left_ = new Node(2);
    root->right_ = new Node(3);
    root->left_->left_ = new Node(4);
    root->left_->right_ = new Node(5);
    root->right_->left_ = new Node(6);
    root->right_->right_ = new Node(7);

    int sum1 = TreeSumRecursive(root);
    int sum2 = TreeSumIterative(root);

    std::cout<<"Recursive function sum = "<<sum1<<std::endl;
    std::cout<<"Iterative fundtion sum = "<<sum2<<std::endl;
    return 0;
}