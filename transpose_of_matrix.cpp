#include <iostream>
#include <vector>
using namespace std;

void printMatrix(vector<vector<int>> &matrix)
{
    for (auto i : matrix)
    {
        for (auto j : i)
        {
            cout << j << ", ";
        }
        cout << endl;
    }
}

// Time complexity: O(N2)
// Auxiliary Space: O(1)
void transpose(vector<vector<int>> &matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1, 1},
                                  {2, 2, 2, 2},
                                  {3, 3, 3, 3},
                                  {4, 4, 4, 4}};
    int n = matrix[0].size();
    transpose(matrix, n);
    printMatrix(matrix);
}