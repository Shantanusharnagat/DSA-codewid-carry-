// binary trees
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    // constructor
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildtree(node *root)
{
    int data;
    cout << "Enter the data" << endl;
    cin >> data;

    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter the child to left of " << data << endl;
    root->left = buildtree(root->left);
    cout << "Enter the child to the right of " << data << endl;
    root->right = buildtree(root->right);

    return root;
}

/*              1
               / \
              3   5
            /  \    \
           7    11   17


*/

// lvl order traversal

void lvlordertraversal(node *root)
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

// inordertraverssal
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

    lvlordertraversal(root);
    cout << "Inorder traversal" << endl;

    inordertraversal(root);

    cout << "Preorder traversal" << endl;

    preordertraversal(root);
    cout << "Postorder traversal" << endl;
    postordertraversal(root);

    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 -1 17 -1 -1