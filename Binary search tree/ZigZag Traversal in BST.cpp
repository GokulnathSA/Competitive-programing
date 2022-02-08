#include<iostream>
#include<stack>

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

void ZigzagTraversal(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    stack<Node*> currlevel;
    stack<Node*> nextlevel;

    bool leftToright = true;

    currlevel.push(root);

    while(!currlevel.empty())
    {
        Node* temp = currlevel.top();
        currlevel.pop();

        if(temp)
        {
            cout<<temp->data<<" ";

            if(leftToright)
            {
                if(temp->left)
                {
                    nextlevel.push(temp->left);
                }

                if(temp->right)
                {
                    nextlevel.push(temp->right);
                }
            }

            else
            {
                if(temp->right)
                {
                    nextlevel.push(temp->right);
                }

                if(temp->left)
                {
                    nextlevel.push(temp->left);
                }
            }
        }

        if(currlevel.empty())
        {
            leftToright = !leftToright;
            swap(currlevel, nextlevel);
        }

    } 
}

int main()
{
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(12);
    root->left->left = new Node(1);
    root->left->right = new Node(2);

    ZigzagTraversal(root);
    return 0;
}