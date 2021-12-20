#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <map>
using namespace std;
/* #define _DEBUG */
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int dp[amount + 1];
        memset(dp, 0x7f, sizeof(dp));
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                if (i - coins[j] < 0)
                {
                    continue;
                }
                int r = i - coins[j];
                if (dp[r] != 0x7f7f7f7f && dp[r] + 1 < dp[i])
                {
                    dp[i] = dp[r] + 1;
                }
            }
        }

        return dp[amount] == 0x7f7f7f7f ? -1 : dp[amount];
    }
};

// for test
int main()
{
    Solution s;
    vector<int> coins1{1, 2, 5};
    cout << s.coinChange(coins1, 11) << endl;
    return 0;
}