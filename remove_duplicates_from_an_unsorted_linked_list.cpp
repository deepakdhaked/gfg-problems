#include <iostream>
#include <unordered_set>
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

node *removeDuplicates(node *head)
{
    node *curr = head;
    node *prev = NULL;
    unordered_set<int> s;
    while (curr != NULL)
    {
        if (s.find(curr->data) != s.end())
        {
            prev->next = curr->next;
        }
        else
        {
            s.insert(curr->data);
            prev = curr;
        }
        curr = prev->next;
    }
    return head;
}