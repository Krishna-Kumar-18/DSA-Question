#include<bits/stdc++.h>
using namespace std;

class node {
    public :
        int data;
        node* left;
        node* right;

        node(int d)
        {
            this->data = d;
            this->left = NULL;
            this->right = NULL;
        }
};

node* insertIntoBST(node* root, int data)
{
    if(root == NULL)
    {
        root = new node(data);
        return root;
    }

    if(data > root->data)
    {
        root->right = insertIntoBST(root->right, data);
    }
    else 
    {
        root->left = insertIntoBST(root->left, data);
    }

    return root;
}

void takeInput(node* &root) 
{
    int data;
    cin >> data;

    while(data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void levelOrderTraversal(node* root) {
    queue<node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        if(temp == NULL) {
            cout << endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else {

            cout << temp->data << " ";

            if(temp->left)
            {
                q.push(temp->left);
            }

            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void inOrderTraversal(node* root)
{
    if(root == NULL)
    {
        return ;
    }

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void preOrderTraversal(node* root)
{
    if(root == NULL)
    {
        return ;
    }

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(node* root)
{
    if(root == NULL)
    {
        return ;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

int main() 
{
    node* root = NULL;    

    cout << "Enter the data for the BST :" << endl;
    takeInput(root);
    cout << endl;

    cout << "Level Order Traversal of the BST :" << endl;
    levelOrderTraversal(root);
    cout << endl;
    cout << endl;

    cout << "In Order Traversal of the BST :" << endl;
    inOrderTraversal(root);
    cout << endl;
    cout << endl;

    cout << "Pre Order Traversal of the BST :" << endl;
    preOrderTraversal(root);
    cout << endl;
    cout << endl;

    cout << "Post Order Traversal of the BST :" << endl;
    postOrderTraversal(root);
    cout << endl;
    cout << endl;

    return 0;
}