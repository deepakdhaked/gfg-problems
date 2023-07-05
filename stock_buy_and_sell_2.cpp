#include <iostream>
#include <vector>
using namespace std;

int stockBuyAndSell(int n, vector<int> &prices)
{
    int profit = 0;
    for (int i = 1; i < n; i++)
    {
        profit = profit + max(0, prices[i] - prices[i - 1]);
    }
    return profit;
}

int main()
{
    vector<int> prices = {3, 4, 1, 5};
    int n = prices.size();
    cout << "Profit earned is : " << stockBuyAndSell(n, prices) << endl;
}