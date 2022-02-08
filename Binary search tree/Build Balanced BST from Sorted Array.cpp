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

Node* arrToBst(int arr[], int start, int end)
{
    if(start>end)
    {
        return NULL;
    }
    int mid = (start + end)/2;
    Node* root = new Node(arr[mid]);

    root->left = arrToBst(arr, start, mid-1);
    root->right = arrToBst(arr, mid+1, end);

    return root;
}

void preorder(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    int arr[] = {1,2,3,4,5};
    Node* root = arrToBst(arr, 0, 4);
    preorder(root);
    cout<<endl;
    return 0;
}