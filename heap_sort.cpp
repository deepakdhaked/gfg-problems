#include <iostream>
using namespace std;

// Time Complexity : O(N*Log(N))
// Space Complexity : O(1);
void heapify(int arr[], int n, int index)
{
    int curr = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (arr[curr] < arr[left] && left < n)
    {
        curr = left;
    }
    if (arr[curr] < arr[right] && right < n)
    {
        curr = right;
    }
    if (curr != index)
    {
        swap(arr[curr], arr[index]);
        heapify(arr, n, curr);
    }
}

void buildHeap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

void heapSort(int arr[], int n)
{
    buildHeap(arr, n);

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}