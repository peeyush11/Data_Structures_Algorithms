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
    
   Node* temp;

   std::queue<Node*> q;

   q.push(root);

   while(!q.empty()){

    temp = q.front();
    q.pop();

    if(temp->data_ == val){
        std::cout<<"value found";
        break;
    }
    
    if(temp->left_)
        q.push(temp->left_);
    if(temp->right_)
        q.push(temp->right_);

   }
   return 0;
}

int main(){

    Node* root = new Node(10);
    root->left_ = new Node(8);
    root->right_ = new Node(12);
    root->left_->left_ = new Node(6);
    root->left_->right_ = new Node(17);
    root->right_->left_ = new Node(5);
    root->right_->right_ = new Node(15);

    int val = 7;
    bool max_val = findElement(root, val);
    
    if(max_val)
        std::cout<<"Value found in tree "<<std::endl;
    else
        std::cout<<"Value not found in tree"<<std::endl;

    return 0;
}