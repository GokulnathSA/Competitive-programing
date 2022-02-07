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

int calDiameter(Node* root, int* height)
{
    if(root==NULL)
    {
        *height=0;
        return 0;
    }
    int lh=0, rh=0;
    int ldiameter = calDiameter(root->left, &lh);
    int rdiameter = calDiameter(root->right, &rh);

    int currdiameter = lh + rh + 1;
    *height = max(lh, rh) + 1;

    return max(currdiameter, max(ldiameter,rdiameter));
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    return 0;
    
}