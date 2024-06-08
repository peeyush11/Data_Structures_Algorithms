#include <bits/stdc++.h>

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

int isSum(Node* root){
    if(root == nullptr) return 0;

    if(root->left == NULL && root->right == NULL) return root->data;

    int left_sum = isSum(root->left);
    int right_sum = isSum(root->right);

    // std::cout<<left_sum<<"\t"<<right_sum<<std::endl;
    
    int sum = left_sum + right_sum;

    if(sum == root->data) return (sum + root->data);
    else return INT_MIN; 
}

bool isSumTree(Node* root){
    if(root == nullptr) return 1;

    return (isSum(root) != INT_MIN);
}

int main(){

    Node* case_1 = new Node(3);
    case_1->left = new Node(1);
    case_1->right = new Node(2);

    Node* case_2 = new Node(10);
    case_2->left = new Node(20);
    case_2->right = new Node(30);
    case_2->left->left = new Node(10);
    case_2->left->right = new Node(10);

    std::cout<<isSumTree(case_1)<<std::endl;
    std::cout<<isSumTree(case_2)<<std::endl;
   
    return 0;
}