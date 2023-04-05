// node
// data address
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructor
    ~Node()
    {
        int value = this->data;

        if (this->next == NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory freed";
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

void insertAthead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertattail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void insertAtmiddle(Node *&head, Node *&tail, int d, int position)
{

    if (position == 1)
    {
        insertAthead(head, d);
        return;
    }
    Node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp->next == NULL)
    {
        insertattail(tail, d);
        return;
    }
    Node *nodetobecreated = new Node(d);
    nodetobecreated->next = temp->next;
    temp->next = nodetobecreated;
}

void deleting(Node *&head, int position, Node *&tail)
{
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *prev = NULL;
        Node *cur = head;

        int cnt = 1;
        while (cnt < position)
        {
            prev = cur;
            cur = cur->next;
            cnt++;
        }
        // last node
        if (cur->next == NULL)
        {
            tail = prev;
        }
        prev->next = cur->next;
        cur->next = NULL;
        delete cur;
    }
}

int main()
{

    Node *node1 = new Node(11);
    Node *head = node1;
    Node *tail = node1;
    print(head);

    insertAthead(head, 9);

    insertAthead(head, 7);

    insertattail(tail, 15);

    insertattail(tail, 18);

    insertAtmiddle(head, tail, 22, 2);
    insertAtmiddle(head, tail, 27, 4);

    insertAtmiddle(head, tail, 1, 1);

    insertAtmiddle(head, tail, 90, 9);

    deleting(head, 1, tail);
    deleting(head, 2, tail);

    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;
    // 9, 11
    print(head);
}