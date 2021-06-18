#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define _DEBUG
#define LL long long

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int len = coins.size();
        int dpPre[amount + 1];
        int dp[amount + 1];
        memset(dpPre, 0, sizeof(dpPre));
        memset(dp, 0, sizeof(dp));
        dpPre[0] = 1;
        for (int i = 0; i < len; i++)
        {
            int coin = coins[i];
            int max = amount / coin;
            for (int j = 0; j <= amount; j++)
            {
                int div = j / coin;
                for (int k = 0; k <= div && j - coin * k >= 0; k++)
                {
                    dp[j] += dpPre[j - coin * k];
                }
#ifdef _DEBUG
                if (dp[j] > 0)
                {
                    cout << "i: " << i << " j: " << j << " dp[i][j]: " << dp[j] << endl;
                }
#endif
            }
            memcpy(dpPre, dp, sizeof(dp));
            memset(dp, 0, sizeof(dp));
        }
        return dpPre[amount];
    }
};

// for test
int main()
{
    Solution s;
    vector<int> t1{1, 2, 5};
    cout << s.change(5, t1) << endl;

    return 0;
}