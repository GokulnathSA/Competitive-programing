#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;

        Node(int val) {
            data = val;
            left = nullptr;
            right = nullptr;
        }
};

bool isBst(Node* root, Node* min = NULL, Node* max = NULL)
{
    if(root==NULL)
    {
        return true;
    }

    if(min!=NULL && root->data <= min->data)
    {
        return false;
    }

    if(max!= NULL && root->data >= max->data)
    {
        return true;
    }

    bool leftValid = isBst(root->left, min, root);
    bool rightValid = isBst(root->right, root, max);

    return leftValid && rightValid;
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    
    if(isBst(root, NULL, NULL))
    {
        cout<<"Valid BST";

    }
    else
    {
        cout<<"Invalid BST";
    }
    return 0;
}