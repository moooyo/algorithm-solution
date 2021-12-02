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
    int max(int a, int b) { return a > b ? a : b; }
    int maxProfit(vector<int> &prices)
    {
        int maxLen = prices.size();
        int dp[maxLen + 1][5];
        memset(dp, 0, sizeof(dp));
        dp[0][1] = -1 * (1e5 + 3);
        dp[0][3] = -1 * (1e5 + 3);
        for (int i = 1; i <= maxLen; i++)
        {
            int price = prices[i - 1];
            dp[i][1] = max(dp[i - 1][1], -1 * price);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + price);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - 1 * price);
            dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + price);
        }
        int m1, m2;
        m1 = max(dp[maxLen][1], dp[maxLen][2]);
        m2 = max(dp[maxLen][3], dp[maxLen][4]);
        return max(m1, m2);
    }
};
// for test
int main()
{
    Solution s;
    vector<int> test1{3, 3, 5, 0, 0, 3, 1, 4};
    vector<int> test2{1, 2, 3, 4, 5};

    cout << s.maxProfit(test1) << endl;
    cout << s.maxProfit(test2) << endl;
    return 0;
}