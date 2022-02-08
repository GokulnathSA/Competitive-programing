#include<iostream>
#include<climits>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

struct Info
{
    int size;
    int max;
    int min;
    int ans;
    bool isBst;

};

Info largestBstInBt(Node* root)
{
    if(root == NULL)
    {
        return {0,INT_MIN, INT_MAX, 0, true};
    }

    if(root->left ==NULL && root->right == NULL)
    {
        return {1, root->data, root->data, 1, true};
    }

    Info leftInfo = largestBstInBt(root->left);
    Info rightInfo = largestBstInBt(root->right);

    Info curr;

    curr.size = (1+ leftInfo.size + rightInfo.size);

    if(leftInfo.isBst && rightInfo.isBst && leftInfo.max < root->data && rightInfo.max > root->data)
    {
        curr.min = min(leftInfo.min, min(rightInfo.min,root->data));
        curr.max = max(rightInfo.max , max(leftInfo.max, root->data));

        curr.ans = curr.size;
        curr.isBst = true;

        return curr;
    }

    curr.ans = max(leftInfo.ans, rightInfo.ans);
    curr.isBst = false;
    return curr;
}

int main()
{
    Node* root = new Node(5);
    root->left = new Node(10);
    root->right = new Node(15);
    root->left->left = new Node(1);

    cout<<"Largest BST on BT: "<<largestBstInBt(root).ans<<endl;
    return 0;

}