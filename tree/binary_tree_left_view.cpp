#include <bits/stdc++.h>

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int x): data(x), left(nullptr), right(nullptr){}
    ~Node(){}
};

std::vector<int> LeftView(Node* root){
        std::vector<int> result;
        std::queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            Node* temp = q.front();
            result.push_back(temp->data);
            int q_size = q.size();

            for(int i=0; i<q_size; i++){
                Node* current = q.front();
                q.pop();

                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
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
    root->left->left->right = new Node(7);

    std::vector<int> left_view = LeftView(root);

    for(int& val: left_view) std::cout<<val<<"\t";


    return 0;
}