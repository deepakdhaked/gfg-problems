#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct node *reverse(struct node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }

    node *next = NULL;
    node *curr = head;
    node *prev = NULL;
    int count = 0;
    while (count < k && curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if (next != NULL)
    {
        head->next = reverse(next, k);
    }
    return prev;
}