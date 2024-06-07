#include <iostream>

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int x): data(x), left(nullptr), right(nullptr){}
    ~Node(){
        delete left;
        delete right;
    }
};

bool isIdentical(Node* root1, Node* root2){

    if(root1 == NULL && root2 == NULL) return 1;
    if(root1 == NULL || root2 == NULL) return 0;

    bool left_tree = isIdentical(root1->left, root2->left);
    bool right_tree = isIdentical(root1->right, root2->right);
    bool root_identical = root1->data == root2->data? 1 : 0;

    if(left_tree && right_tree && root_identical) return 1;
    else return 0;
}

int main(){

    // Case 1
    Node* r1 = new Node(6);
    r1->left = new Node(4);
    r1->right = new Node(8);
    r1->left->left = new Node(3);
    r1->left->right = new Node(5);
    r1->right->left = new Node(7);
    r1->right->right = new Node(9);

    Node* r2 = new Node(6);
    r2->left = new Node(4);
    r2->right = new Node(8);
    r2->left->left = new Node(3);
    r2->left->right = new Node(5);
    r2->right->left = new Node(7);
    r2->right->right = new Node(9);

    // Case 2
    Node* c1 = new Node(6);
    c1->left = new Node(4);
    c1->right = new Node(8);
    c1->left->left = new Node(3);
    c1->left->right = new Node(5);
    c1->right->left = new Node(7);
    c1->right->right = new Node(9);

    Node* c2 = new Node(6);
    c2->left = new Node(4);
    c2->right = new Node(8);
    c2->left->left = new Node(1);
    c2->left->right = new Node(5);
    c2->right->left = new Node(7);
    c2->right->right = new Node(9); 

    bool case_1 = isIdentical(r1, r2);
    bool case_2 = isIdentical(c1, c2);

    std::cout<<"Case 1: "<< (case_1 ? "identical" : "not identical") << std::endl;
    std::cout<<"Case 2: "<< (case_2 ? "identical" : "not identical") << std::endl;

    return 0;
}