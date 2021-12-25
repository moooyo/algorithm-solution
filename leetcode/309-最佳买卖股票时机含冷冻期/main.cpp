#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstring>
using namespace std;
#define DEBUG
#define INF 0x7f7f7f7f
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int len = prices.size();
        int dp[len + 1][3];
        memset(dp, 0, sizeof(dp));
        // dp[0] 不持有股票且不在冷却期
        // dp[1] 不持有股票但在冷却期
        // dp[2] 持有股票
        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[0][2] = -1 * INF;
        for (int i = 1; i <= len; i++)
        {
            int price = prices[i - 1];
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = max(0, dp[i - 1][2] + price);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][0] - price);
        }

#ifdef DEBUG
#endif

        return max(dp[len][0], dp[len][1]);
    }
};
// for test
int main()
{
    Solution s;
    vector<int> test1{1, 2, 3, 0, 2};
    vector<int> test2{1, 2, 3, 4, 5};

    cout << s.maxProfit(test1) << endl;
    // cout << s.maxProfit(test2) << endl;
    return 0;
}