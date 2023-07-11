#include <iostream>
#include <vector>
using namespace std;

int findK(vector<vector<int>> &matrix, int n, int m, int k)
{
    int top = 0, bottom = n - 1, left = 0, right = m - 1, count = 0;

    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            count++;
            if (count == k)
            {
                return matrix[top][i];
            }
        }
        top++;

        for (int i = top; i <= bottom; i++)
        {
            count++;
            if (count == k)
            {
                return matrix[i][right];
            }
        }
        right--;
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                count++;
                if (count == k)
                {
                    return matrix[bottom][i];
                }
            }
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                count++;
                if (count == k)
                {
                    return matrix[i][left];
                }
            }
            left++;
        }
    }
    return -1;
}

int main()
{
    int n = 4, m = 4, k = 10;
    vector<vector<int>> matrix = {{1, 2, 3, 4},
                                  {5, 6, 7, 8},
                                  {9, 10, 11, 12},
                                  {13, 14, 15, 16}};
    cout << "Kth element is : " << findK(matrix, n, m, k) << endl;
}