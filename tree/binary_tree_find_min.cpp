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

int FindMinIterativeDFS(Node* root){

    // this mehtod is iterative depth first traversal.
    // it is implemented using stack.
    std::stack<Node*> st;
    st.push(root);
    Node* current;
    int min_val = INT_MAX;
    
    while(!st.empty()){
        current = st.top();
        if(current->data_ < min_val) min_val = current->data_;
        st.pop();

        if(current->right_) st.push(current->right_);
        if(current->left_) st.push(current->left_);

    }
    return min_val;
}

int FindMinBFS(Node* root){

    // this method uses breadth first traversal also called as level order traversal.
    // it is always implemented using queue. It is an iterative solution.
    std::queue<Node*> q;
    q.push(root);
    Node* current;
    int min_val = INT_MAX;

    while(!q.empty()){

        current = q.front();
        if(current->data_ < min_val) min_val = current->data_;
        q.pop();

        if(current->left_) q.push(current->left_);
        if(current->right_) q.push(current->right_);
    }

    return min_val;
}

int FindMinDFSRecursive(Node* root){

    // this method is recursive depth first traversal
    if(root == nullptr) return INT_MAX;

    int left_min = FindMinDFSRecursive(root->left_);
    int right_min = FindMinDFSRecursive(root->right_);

    return std::min({root->data_, left_min, right_min});
}

int main(){

    Node* root = new Node(10);
    root->left_ = new Node(8);
    root->right_ = new Node(12);
    root->left_->left_ = new Node(6);
    root->left_->right_ = new Node(17);
    root->right_->left_ = new Node(5);
    root->right_->right_ = new Node(15);

    int min_dfs_iterative = FindMinIterativeDFS(root);
    int min_bfs = FindMinBFS(root);
    int min_dfs_recursive = FindMinDFSRecursive(root);

    std::cout<<"Iterative DFS, minimum value in tree: "<<min_dfs_iterative<<std::endl;
    std::cout<<"BFS, minimum value in tree: "<<min_bfs<<std::endl;
    std::cout<<"DFS Recursive, minimum value in tree: "<<min_dfs_recursive<<std::endl;
    return 0;
}