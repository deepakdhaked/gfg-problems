#include <iostream>
#include <vector>
using namespace std;

void mutliply(vector<vector<int>> &matrixA, vector<vector<int>> &matrixB)
{
    int n = matrixA.size();
    vector<vector<int>> temp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                temp[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    matrixA = temp;
}

int main()
{
    vector<vector<int>> matrixA = {{1, 2}, {3, 4}};
    vector<vector<int>> matrixB = {{4, 3}, {2, 1}};
    mutliply(matrixA, matrixB);
    for (auto i : matrixA)
    {
        for (int j : i)
        {
            cout << j << ", ";
        }
        cout << endl;
    }
}