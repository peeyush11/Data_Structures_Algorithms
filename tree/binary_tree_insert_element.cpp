#include <iostream>
#include <queue>

struct Node{
    int data_;
    Node* left_;
    Node* right_;

    Node(int data) : data_(data), left_(nullptr), right_(nullptr){}
    ~Node(){}
};

void insertElement(Node*& root, const int& val){
    
    // Using level order traversal for insertion.
    if(root == nullptr)
        root = new Node(val);
    else{

        std::queue<Node*> q;
        q.push(root);
        Node* temp;

        while(!q.empty()){
            temp = q.front();
            q.pop();

            if(temp->left_)
                q.push(temp->left_);
            else{
                temp->left_ = new Node(val);
                break;
            }

            if(temp->right_)
                q.push(temp->right_);
            else{
                temp->right_ = new Node(val);
                break;
            }
        }
    }

}

void printInOrder(Node* root){

    if(root == nullptr) return;

    printInOrder(root->left_);
    std::cout<<root->data_<<"\t";
    printInOrder(root->right_);
}

int main(){

    Node* root = nullptr;
    insertElement(root, 10);
    insertElement(root, 11);
    insertElement(root, 5);
    printInOrder(root);

    return 0;
}