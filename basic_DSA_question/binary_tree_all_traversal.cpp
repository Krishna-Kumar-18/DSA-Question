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

node* buildTree(node* root)
{
    cout << "Enter the data" << endl;
    int data;
    cin >> data;

    root = new node(data);

    if(data == -1)
    {
        return NULL;
    }

    cout << "Enter data for left of data " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for right of data " << data << endl ;
    root->right = buildTree(root->right);

    return root;
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

    root = buildTree(root);
    cout << endl;

    cout << "Level order traversal of the data is : " << endl;
    levelOrderTraversal(root);
    cout << endl;

    cout << "In order traversal of the data is : " << endl; 
    inOrderTraversal(root);
    cout << endl;

    cout << "Pre order traversal of the data is :" << endl;
    preOrderTraversal(root);
    cout << endl;

    cout << "Post order traversal of the data is :" << endl;
    postOrderTraversal(root);

    return 0;
}