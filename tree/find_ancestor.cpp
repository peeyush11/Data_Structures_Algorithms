#include <iostream>
#include <vector>
#include <memory>

// For recursive method
// Time complexity: O(n) where n is the number of nodes in the given binary tree.
// Space Complexity: O(h) where h is the height of the given binary tree.

// For iterative method
// Time complexity: O(n) where n is the number of nodes in the given binary tree.
// Space complexity: O(h) where h is the height of the given binary tree.

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int x): data(x), left(nullptr), right(nullptr){}

    ~Node(){}
};

int HelperFunction(Node* root, int& target, std::vector<int>& result){

    if(root == NULL) return 0;

    if(root->data == target) return 1;

    if(HelperFunction(root->left, target, result) || HelperFunction(root->right, target, result)){
        result.push_back(root->data);
        return 1;
    }

    return 0;
}

std::vector<int> FindAncestorsRecursive(Node* root, int target){

    std::vector<int> result;

    HelperFunction(root, target, result);

    return result;

}

auto& FindAncestorsIterative(Node* root, int target){

    auto result = std::make_unique<std::vector<int>>;


    return std::move(result);
}

int main(){

    Node* root =  new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(7);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    int target = 7;

    auto result = FindAncestorsRecursive(root, target);
    
    for(auto& val:result){
        std::cout<<val<<"\t";
    }
    std::cout<<std::endl;
    return 0;

}
