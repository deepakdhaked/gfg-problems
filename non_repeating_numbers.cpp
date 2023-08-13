#include <iostream>
#include <vector>
using namespace std;

// Time Complexity : O(N)
// Space Complexity : O(1)
vector<int> singleNumber(vector<int> nums)
{
    int xor_result = 0;

    // Calculate the XOR of all numbers in the array
    for (int i : nums)
    {
        xor_result ^= i;
    }

    // Find the rightmost set bit mask
    int rightmost_setbit_mask = xor_result & (-xor_result);

    // Initialize the distinct numbers
    int distinct1 = 0;
    int distinct2 = 0;

    // Divide the array into two groups based on the rightmost set bit
    for (int i : nums)
    {
        if (i & rightmost_setbit_mask)
        {
            distinct1 ^= i;
        }
        else
        {
            distinct2 ^= i;
        }
    }

    // Return the distinct numbers in increasing order
    if (distinct1 < distinct2)
    {
        return {distinct1, distinct2};
    }
    else
    {
        return {distinct2, distinct1};
    }
}