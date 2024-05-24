#include <iostream>
#include <queue>

struct Node{
    int data_;
    Node* left_;
    Node* right_;

    Node(int data) : data_(data), left_(nullptr), right_(nullptr){}
    ~Node(){}
};

class BinaryTree{

public:
    Node* root;

    BinaryTree() : root(nullptr){}

    void insert(int value);

    void printInOrder(Node* temp);

    void printPreOrder(Node* temp);

    void printPostOrder(Node* temp);

    void inOrderTraversal();

    void preOrderTraversal();

    void postOrderTraversal();

    void levelOrderTraversal();


};

void BinaryTree::insert(int value){

    if(root == nullptr){
        root = new Node(value);
        return;
    }

    // create a queue to insert elements in level order format
    std::queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp->left_ == nullptr){
            temp->left_ = new Node(value);
            break;
        }
        else
            q.push(temp->left_);

        if(temp->right_ == nullptr){
            temp->right_ = new Node(value);
            break;
        }
        else
            q.push(temp->right_);
    }

}

void BinaryTree::printInOrder(Node* temp){

    if(temp == nullptr) return;

    printInOrder(temp->left_);

    std::cout<<temp->data_<<"\t";

    printInOrder(temp->right_);
}

void BinaryTree::inOrderTraversal(){

    printInOrder(root);

    std::cout<<std::endl;

}

void BinaryTree::printPreOrder(Node* temp){

    if(temp == nullptr) return;

    std::cout<<temp->data_<<"\t";

    printPreOrder(temp->left_);

    printPreOrder(temp->right_);
}

void BinaryTree::preOrderTraversal(){

    printPreOrder(root);

    std::cout<<std::endl;
}

void BinaryTree::printPostOrder(Node* temp){

    if(temp == nullptr) return;

    printPostOrder(temp->left_);

    printPostOrder(temp->right_);

    std::cout<<temp->data_<<"\t";
}

void BinaryTree::postOrderTraversal(){

    printPostOrder(root);

    std::cout<<std::endl;
}

void BinaryTree::levelOrderTraversal(){

    std::queue<Node*> q;

    q.push(root);

    while(!q.empty()){

        Node* temp = q.front();
        std::cout<<temp->data_<<"\t";
        q.pop();

        if(temp->left_ != nullptr)
            q.push(temp->left_);

        if(temp->right_ != nullptr)
            q.push(temp->right_);
    }
}

int main(){

    // Node* root = new Node(10);
    // root->left_ = new Node(8);
    // root->right_ = new Node(12);
    // root->left_->left_ = new Node(5);
    // root->left_->right_ = new Node(7);
    // root->right_->left_ = new Node(15);
    // root->right_->right_ = new Node(17);

    BinaryTree tree;

    // insert nodes into the tree
    tree.insert(10);
    tree.insert(8);
    tree.insert(12);
    tree.insert(5);
    tree.insert(7);
    tree.insert(15);
    //tree.insert(17);

    std::cout<<"Inorder: "<<std::endl;
    tree.inOrderTraversal();
    std::cout<<"PreOrder: "<<std::endl;
    tree.preOrderTraversal();
    std::cout<<"PostOrder: "<<std::endl;
    tree.postOrderTraversal();
    std::cout<<"LevelOrder:"<<std::endl;
    tree.levelOrderTraversal();
    return 0;
}