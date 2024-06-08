#include <bits/stdc++.h>

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int x) : data(x), left(nullptr), right(nullptr) {}

    ~Node()
    {
        delete left;

        delete right;
    }
};

void MirrorTree(Node *root)
{
    if (root == NULL)
        return;

    MirrorTree(root->left);
    MirrorTree(root->right);

    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;
}

void InorderPrint(Node *root)
{

    if (root == nullptr)
        return;

    InorderPrint(root->left);
    std::cout << root->data << "\t";
    InorderPrint(root->right);
}
int main()
{

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    MirrorTree(root);
    InorderPrint(root);
    return 0;
}