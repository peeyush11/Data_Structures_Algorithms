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

std::vector<int> RightView(Node* root){

    std::queue<Node*> q;
    q.push(root);
    std::vector<int> result;

    while(!q.empty()){
        Node* right_most_node = q.front();
        result.push_back(right_most_node->data);
        int q_size = q.size();
        

        for(int i= 0; i<q_size; i++){
            Node* current = q.front();
            q.pop();

            if(current->right) q.push(current->right);

            if(current->left) q.push(current->left);
         }
    }

    return result;
}

int main(){

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->right->left = new Node(8);

    std::vector<int> right_view = RightView(root);

    for(int& val: right_view) std::cout<<val<<"\t";


    return 0;
}