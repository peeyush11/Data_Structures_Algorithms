#include <iostream>
#include <queue>
#include <stack>

struct Node{
    int data_;
    Node* left_;
    Node* right_;

    Node(int data) : data_(data), left_(nullptr), right_(nullptr){}
    ~Node(){}
};

void LevelOrderTraversalInReverse(Node* root){

    std::queue<Node*> q;
    std::stack<Node*> st;

    q.push(root);

    Node* temp;

    while(!q.empty()){

        temp = q.front();
        q.pop();
        st.push(temp);

        if(temp->right_)
            q.push(temp->right_);

        if(temp->left_)
            q.push(temp->left_);    
    }

    while(!st.empty()){

        std::cout<<st.top()->data_<<"\t";
        st.pop();
    }

}

int main(){

    Node* root = new Node(1);
    root->left_ = new Node(2);
    root->right_ = new Node(3);
    root->left_->left_ = new Node(4);
    root->left_->right_ = new Node(5);
    root->right_->left_ = new Node(6);
    root->right_->right_ = new Node(7);

    LevelOrderTraversalInReverse(root);   
    
    return 0;
}