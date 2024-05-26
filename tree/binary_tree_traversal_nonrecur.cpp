#include <iostream>
#include <queue>
#include <stack>

// For depth first search of a binary tree, stack data structure is always used.

struct Node{
    int data_;
    Node* left_;
    Node* right_;

    Node(int data) : data_(data), left_(nullptr), right_(nullptr){}
    ~Node(){}
};

void PreOrderTraversalNonRecursive(Node* root){

    if(root == nullptr){
        std::cout<<"Tree is empty"<<std::endl;
        return;
    }
    std::stack<Node*> st;
    st.push(root);
    Node* visited = nullptr;

    while(!st.empty()){

        visited = st.top();
        st.pop();
        std::cout<<visited->data_<<"\t";

        if(visited->right_) st.push(visited->right_);
        if(visited->left_)  st.push(visited->left_);
    }

    std::cout<<std::endl;
}

void InOrderTraversalNonRecursive(Node* root){

     if(root == nullptr){
        std::cout<<"Tree is empty"<<std::endl;
        return;
    }

    std::stack<Node*> st;
    Node* current = root;

    while(current != nullptr || !st.empty()){

        // reach the leftmost node of the current node
        while(current != nullptr){

            // place the current node on the stack before traversing to the left
            st.push(current);
            current = current->left_;

            //this loop breaks when the current node reaches the leaf node and then becomes nullptr after that

        }

        // current must be nullptr at this time.
        current = st.top();
        st.pop();

        std::cout<<current->data_<<"\t";

        // till this point we have visited the node and it's left subtree, now it's time for right subtree.

        current = current->right_;

    }
    std::cout<<std::endl;
}

void PostOrderTraversalNonRecursive(Node* root){

    if(root == nullptr){
        std::cout<<"Tree is empty"<<std::endl;
        return;
    }

    std::stack<Node*> st;
    Node* current = root;
    Node* previous = nullptr;

    do{
        while(current != nullptr){
            st.push(current);
            current = current->left_;
        }

        // At this point current should be nullptr and stack not empty.
        while(current == NULL && !st.empty()){
            current = st.top();
            // this condition checks if the node is a leaf node or if it is re visited.
            if(current->right_ == NULL || current->right_ == previous){
                std::cout<<current->data_<<"\t";
                st.pop();
                previous = current;
                current = nullptr;
            }
            else{
                current = current->right_;
            }
        }


    }while(!st.empty());

    std::cout<<std::endl;
}

int main(){

    Node* root = new Node(1);
    root->left_ = new Node(2);
    root->right_ = new Node(3);
    root->left_->left_ = new Node(4);
    root->left_->right_ = new Node(5);
    root->right_->left_ = new Node(6);
    root->right_->right_ = new Node(7);

    //empty tree case
    // Node* root = nullptr;

    PreOrderTraversalNonRecursive(root);   
    InOrderTraversalNonRecursive(root);
    PostOrderTraversalNonRecursive(root);
    return 0;
}