#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildtree(node *root)
{

    int data;
    cout << "Enter data" << endl;

    cin >> data;

    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data to insert in left of" << data << endl;
    root->left = buildtree(root->left);
    cout << "Enter data to insert in right of" << data << endl;
    root->right = buildtree(root->right);

    return root;
}

void levelordertraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();

        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void inordertraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    inordertraversal(root->left);
    cout << root->data << " ";
    inordertraversal(root->right);
}

void preordertraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preordertraversal(root->left);
    preordertraversal(root->right);
}

void postordertraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

       postordertraversal(root->left);
    postordertraversal(root->right);
    cout << root->data << " ";
}

int main()
{
    node *root = NULL;

    root = buildtree(root);

    levelordertraversal(root);
    cout << "INORDER TRAVERSAL" << endl;
    inordertraversal(root);
    cout << "PREORDER TRAVERSAL" << endl;

    preordertraversal(root);
    cout << "Postorder traversal" << endl;
    postordertraversal(root);

    return 0;
}