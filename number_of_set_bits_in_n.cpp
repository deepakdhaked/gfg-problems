#include <iostream>
using namespace std;

// Brian Kernighan’s Algorithm:
// Time Complexity: O(log n)
// Auxiliary Space: O(1)
int numberofSetBits(int n)
{
    // The reason this algorithm takes logarithmic time complexity (O(log(n))) is that, in each iteration, it clears the least significant set bit, reducing the number of bits by at least one. Since an integer typically has log(n) bits, where n is the value of the integer, the algorithm performs log(n) iterations.
    int count = 0;
    while (n != 0)
    {
        int rmsb_mask = n & (-n);
        n -= rmsb_mask;
        count++;
    }
    return count;
}

int main()
{
    int n = 96;
    cout << "Number of Set Bits are : " << numberofSetBits(n) << endl;
}