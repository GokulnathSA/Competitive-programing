#include<iostream>
using namespace std;

class Node
{
    
    int data;

    Node* left;
    Node* right;
    public:
        Node(int val)
        {
            data = val;
            left = NULL;
            right = NULL;
        }
};

int search(int inorder[], int start, int end, int curr)
{
    for(int i=start; i<=end;i++)
    {
        if(inorder[i]==curr)
        {
            return i;
        }
    }
    return -1;
}

Node* buildTree(int preoreder[], int inorder[], int start, int end)
{
    static int idx = 0;
    if(start>end) return NULL;
    int curr = preoreder[idx];
    idx++;

    Node* node = new Node(curr);
    if(start == end) return node;

    int pos  = search(inorder, start, end, curr);
    node->left = buildTree(preoreder,inorder,start,pos-1);
    node->right = buildTree(preoreder,inorder,pos+1,end);

    return node;

}

void inorderprint(Node* root)
{
    if(root==NULL) return;
    inorderprint(root->left);
    cout<<root->data<<" ";
    inorderprint(root->right);
}

int main()
{
    int preorder[] = {1,2,4,3,5};
    int inorder[] = {4,2,1,5,3};

    Node* root = buildTree(preorder, inorder, 0, 4);
    inorderprint(root);
    return 0;
}