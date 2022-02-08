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

Node* constBst(int preorder[], int *idx, int key, int min, int max, int n)
{
    if(*idx >= n)
    {
        return NULL;
    }
    Node* root = NULL;
    if(key>min && key< max)
    {
        root = new Node(key);
        *idx = *idx + 1;

        if(*idx < n)
        {
            root->left = constBst(preorder, idx, preorder[*idx], min, key, n);

        }
        if(*idx < n)
        {
            root->right = constBst(preorder, idx, preorder[*idx], key, max, n);
        }

    }
    return root;
}

void printpreorder(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    printpreorder(root->left);
    printpreorder(root->right);
}

int main()
{
    int preorder[] = {10,2,1,13,11};
    int n=5;
    int idx =0;
    Node* root = constBst(preorder, &idx, preorder[0], INT_MIN, INT_MAX, 5);

    printpreorder(root);
    return 0;
}