#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// Time Complexity : O(N) + O(N)
// Space Complexity : O(1)
Node *segregate(Node *head)
{
    int arr[3] = {0};
    Node *temp = head;

    while (temp != NULL)
    {
        arr[temp->data]++;
        temp = temp->next;
    }

    temp = head;
    while (temp != NULL)
    {
        if (arr[0] != 0)
        {
            temp->data = 0;
            arr[0]--;
        }
        else if (arr[1] != 0)
        {
            temp->data = 1;
            arr[1]--;
        }
        else
        {
            temp->data = 2;
            arr[2]--;
        }
        temp = temp->next;
    }
    return head;
}

void insertAtTail(Node *&tail, Node *curr)
{
    tail->next = curr;
    tail = curr;
}

// Time Complexity : O(N)
// Space Complexity : O(1)
Node *segregate(Node *head)
{
    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;

    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;

    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;

    Node *curr = head;
    while (curr != NULL)
    {
        int value = curr->data;

        if (value == 0)
        {
            insertAtTail(zeroTail, curr);
        }
        else if (value == 1)
        {
            insertAtTail(oneTail, curr);
        }
        else if (value == 2)
        {
            insertAtTail(twoTail, curr);
        }
        curr = curr->next;
    }

    if (oneHead->next != NULL)
    {
        zeroTail->next = oneHead->next;
    }
    else
    {
        zeroTail->next = twoHead->next;
    }

    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    head = zeroHead->next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}