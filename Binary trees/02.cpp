#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// inserting
void insertingathead(Node *&head, int d)
{
    Node *newnode = new Node(d);
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}
void insertatend(Node *&tail, int d)
{
    Node *newnode = new Node(d);
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}

void insertinmiddle(Node *&head, Node *&tail, int d, int position)
{
    if (position == 1)
    {
        insertingathead(head, d);
        return;
    }
    else
    {
        int cnt = 1;
        Node *newnode = new Node(d);
        Node *temp = head;
        while (cnt < position - 1)
        {
            temp = temp->next;
            cnt++;
        }
        if (temp->next == NULL)
        {
            insertatend(tail, d);
            return;
        }
        newnode->next = temp->next;
        temp->next->prev = newnode;
        temp->next = newnode;
        newnode->prev = temp;
    }
}

// deleting

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;

    insertingathead(head, 9);
    insertingathead(head, 7);

    insertatend(tail, 11);
    insertatend(tail, 12);

    insertinmiddle(head, tail, 22, 3);

    print(head);
}