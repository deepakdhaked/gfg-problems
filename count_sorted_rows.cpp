#include <iostream>
#include <vector>
using namespace std;

int sortedCount(int n, int m, vector<vector<int>> matrix)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int sorted = 0;
        for (int j = 0; j < m-1; j++)
        {
            if (matrix[i][j] < matrix[i][j + 1])
            {
                sorted++;
            }
            else if (matrix[i][j] > matrix[i][j + 1])
            {
                sorted--;
            }
        }
        if (sorted == m - 1 || sorted == 1 - m)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3},
                                  {6, 5, 4},
                                  {7, 9, 8}};
    int n = matrix.size(), m = matrix[0].size();
    cout << "Number of sorted rows are : " << sortedCount(n, m, matrix) << endl;
}