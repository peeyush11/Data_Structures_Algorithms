#include <iostream>
#include <algorithm>
#include <queue>

struct Node{
    int data_;
    Node* left_;
    Node* right_;

    Node(int val): data_(val), left_(nullptr), right_(nullptr) {}
    ~Node(){}
};

int TreeHeight(Node* root){
    // base case: null node
    if(root == NULL) return 0;
    
    // base case: leaf node
    // if(root->left_ == NULL & root->right_ == NULL) return 1;

    int left_height = TreeHeight(root->left_);
    int right_height = TreeHeight(root->right_);

    // std::cout<<left_height<<"\t"<<right_height<<"\n";
    int max_height = std::max({left_height, right_height});
    // std::cout<<max_height<<"\n";

    return max_height + 1;

}

int TreeHeightBFS(Node * root){
    if(root == NULL) return 0;

    std::queue<Node*> q;
    q.push(root);
    int height = 0;
    
    while(!q.empty()){

        int level_size = q.size();
        for(int i= 0; i < level_size; i++){
            Node* current = q.front();
            q.pop();

            if(current->left_) q.push(current->left_);
            if(current->right_) q.push(current->right_);
        }

        height++;
    }

    return height;

}

int main(){

    Node* case_1 = new Node(5);
    case_1->left_ = new Node(3);
    case_1->left_->left_ = new Node(2);
    case_1->left_->left_->left_ = new Node(4);
    case_1->left_->left_->left_->left_ = new Node(1);

    Node* case_2 = new Node(5);
    case_2->left_ = new Node(3);
    case_2->right_ = new Node(4);
    case_2->left_->left_ = new Node(2);
    case_2->left_->right_ = new Node(1);

    int case_1_height = TreeHeight(case_1);
    int case_2_height = TreeHeight(case_2);

    std::cout<<"Case 1 Recursive function height: "<<case_1_height<<std::endl;
    std::cout<<"Case 2 Recursive function height: "<<case_2_height<<std::endl;

    case_1_height = TreeHeightBFS(case_1);
    case_2_height = TreeHeightBFS(case_2);

    std::cout<<"Case 1 BFS height: "<<case_1_height<<std::endl;
    std::cout<<"Case 2 BFS height: "<<case_2_height<<std::endl;

}