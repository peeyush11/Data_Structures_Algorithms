#include <iostream>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>

struct Node{
    int data_;
    Node* left_;
    Node* right_;

    Node(int data) : data_(data), left_(nullptr), right_(nullptr){}
    ~Node(){}
};

int FindMaxDfsRecursive(Node* root){

    if(root == nullptr) return INT_MIN;

    int left_max = FindMaxDfsRecursive(root->left_);
    int right_max = FindMaxDfsRecursive(root->right_);

    return std::max({root->data_, left_max, right_max}); 
}

int FindMaxDfsIterative(Node* root){
    // this method is iterative solution for DFS in binary tree.
    // it is implemented using stack
    std::stack<Node*> st;
    st.push(root);
    Node* current;
    int max_val = INT_MIN;

    while(!st.empty()){

        current = st.top();
        if(current->data_ > max_val) max_val = current->data_;
        st.pop();

        if(current->right_) st.push(current->right_);
        if(current->left_) st.push(current->left_);
    }

    return max_val;
}

int FindMaxBfs(Node* root){
    // this level order traversal in a binary tree.
    // it is implemented using a queue.
    std::queue<Node*> q;
    q.push(root);
    Node* current;
    int max_val = INT_MIN;

    while(!q.empty()){
        current = q.front();
        if(current->data_ > max_val) max_val = current->data_;
        q.pop();

        if(current->left_) q.push(current->left_);
        if(current->right_) q.push(current->right_);

    }

    return max_val;
}

int main(){

    Node* root = new Node(10);
    root->left_ = new Node(8);
    root->right_ = new Node(12);
    root->left_->left_ = new Node(6);
    root->left_->right_ = new Node(17);
    root->right_->left_ = new Node(5);
    root->right_->right_ = new Node(15);


    int max_val_dfs_recursive = FindMaxDfsRecursive(root);
    int max_val_dfs_iterative = FindMaxDfsIterative(root);
    int max_val_bfs = FindMaxBfs(root);

    std::cout<<"DFS recurisve, max value in binary tree: "<< max_val_dfs_recursive<<std::endl;
    std::cout<<"DFS iterative, max value in binary tree: "<< max_val_dfs_iterative<<std::endl;
    std::cout<<"BFS iterative, max value in binary tree: "<< max_val_bfs<<std::endl;
    return 0;
}