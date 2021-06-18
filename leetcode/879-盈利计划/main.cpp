#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define _DEBUG
#define LL long long

class Solution
{
public:
    const int MOD = 1e9 + 7;
    int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit)
    {
        const int len = group.size();
        int MAX = 0;
        for (int i = 0; i < len; i++)
        {
            MAX += profit[i];
        }
        MAX += 1;
        LL dpPre[MAX][n + 1];
        LL dp[MAX][n + 1];
        memset(dp, 0, sizeof(dp));
        memset(dpPre, 0, sizeof(dpPre));
        dpPre[0][0] = 1;
        for (int i = 1; i <= len; i++)
        {
            int v = profit[i - 1];
            int t = group[i - 1];
            for (int k = 0; k < MAX; k++)
            {
                for (int j = 0; j <= n; j++)
                {
                    dp[k][j] += dpPre[k][j];
                    if (k - v >= 0 && j - t >= 0)
                    {
                        dp[k][j] += dpPre[k - v][j - t];
                    }
                    if (dp[k][j] > MOD)
                    {
                        dp[k][j] %= MOD;
                    }
#ifdef _DEBUG
                    if (dp[k][j] != 0)
                    {
                        cout << "i: " << i << " k: " << k << " j: " << j << " dp[k][j]: " << dp[k][j] << endl;
                    }
#endif
                }
            }
            memcpy(dpPre, dp, sizeof(dpPre));
            memset(dp, 0, sizeof(dp));
        }
        LL sum = 0;
        for (int i = minProfit; i < MAX; i++)
        {
            for (int j = 0; j <= n; j++)
            {
#ifdef _DEBUG
                if (dpPre[i][j] != 0)
                {
                    cout << "i: " << i << " j: " << j << " dp: " << dpPre[i][j] << endl;
                }
#endif
                sum += dpPre[i][j];
                if (sum > MOD)
                {
                    sum %= MOD;
                }
            }
        }
        return sum % MOD;
    }
};

// for test
int main()
{
    Solution s;

    vector<int> g1{2, 2};
    vector<int> p1{2, 3};
    cout << s.profitableSchemes(5, 3, g1, p1) << endl;

    vector<int> g2{2, 3, 5};
    vector<int> p2{6, 7, 8};
    cout << s.profitableSchemes(10, 5, g2, p2) << endl;

    vector<int> g3{2, 2, 2, 2, 2};
    vector<int> p3{1, 2, 1, 1, 0};
    cout << s.profitableSchemes(1, 1, g3, p3) << endl;
    return 0;
}