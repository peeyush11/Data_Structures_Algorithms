#include <iostream>
#include <climits>
#include <algorithm>

struct Node{

    int data_;
    Node* left_;
    Node* right_;

    Node(int val) : data_(val), left_(nullptr), right_(nullptr) {}
    ~Node(){}
};

int MaxPathSum(Node* root){

    // base case: if the root node is null i.e. one child is null and other child exists.
    if(root == NULL) return INT_MIN;

    // base case: check if reached leaf node
    if(root->left_ == NULL && root->right_ == NULL) return root->data_;

    // traverse in subtrees
    int sum_left = MaxPathSum(root->left_);
    int sum_right = MaxPathSum(root->right_);

    int max = std::max({sum_left, sum_right});

    return (root->data_ + max);

}

int main(){

    Node* root = new Node(5);
    root->left_ = new Node(11);
    root->right_ = new Node(3);
    root->left_->left_ = new Node(4);
    root->left_->right_ = new Node(2);
    root->right_->right_ = new Node(1);

    int sum = MaxPathSum(root);

    std::cout<<"Max path sum: "<<sum<<std::endl;

    return 0;
}