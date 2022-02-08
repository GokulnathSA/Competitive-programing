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

Node* searchBst(Node* root, int key)
{
    if(root==NULL)
    {
        return NULL;
    }

    if(root->data == key)
    {
        return root;
    }

    if(root->data > key)
    {
        return searchBst(root->left, key);
    }
  
    return searchBst(root->right, key);
    
}

int main()
{
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);

    Node* ans = searchBst(root, 5);
    if(ans == NULL)
    {
        cout<<"Key doesn't exist";
    }
    else
    {
        cout<<"Key exists";
    }
    
    return 0;
}