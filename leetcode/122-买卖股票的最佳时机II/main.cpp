#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstring>
using namespace std;
/* #define _DEBUG */
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int ret = 0;
        int maxLen = prices.size();
        // 0 sale
        // 1 not sale
        int cost = 1e5 + 3;
        for (int i = 1; i <= maxLen; i++)
        {
            int price = prices[i - 1];
            if (price > cost)
            {
                ret += price - cost;
                cost = price;
            }
            else
            {
                cost = price;
            }
        }
        return ret;
    }
};
// for test
int main()
{
    Solution s;
    vector<int> test1{7, 1, 5, 3, 6, 4};
    cout << s.maxProfit(test1) << endl;
    return 0;
}