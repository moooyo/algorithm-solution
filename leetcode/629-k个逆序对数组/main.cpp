#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

/* #define _DEBUG */

const int MOD = 1000000000 + 7;

class Solution
{
public:
    int kInversePairs(int n, int k)
    {
        int dp[n + 1][k + 1];
        int sum[n + 2][k + 2];
        memset(dp, 0, sizeof(dp));
        memset(sum, 0, sizeof(sum));
        for (int i = 1; i <= n; i++)
        {
            dp[i][0] = 1;
            sum[i][1] = 1;
        }
        sum[n + 1][1] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                int total = 0;
                if (j - i + 1 >= 0)
                {
                    total = sum[i - 1][j + 1] - sum[i - 1][j - i + 1];
                }
                else
                {
                    total = sum[i - 1][j + 1] - sum[i - 1][0];
                }
                if (total < 0)
                {
                    total += MOD;
                }

                dp[i][j] = total % MOD;

                sum[i][j + 1] = (sum[i][j] + dp[i][j]) % MOD;
/*
                for (int r = j; r >= j - i + 1 && r >= 0; r--)
                {
                    total = (total + dp[i - 1][r]) % MOD;
                }

                dp[i][j] = total;*/
#ifdef _DEBUG
                cout << "i: " << i << " j: " << j << endl;
                cout << dp[i][j] << " " << sum[i][j + 1] << endl;
#endif
            }
        }
        return dp[n][k];
    }
};

// for test
int main()
{
    Solution s;
    cout << s.kInversePairs(3, 0) << endl;
    cout << s.kInversePairs(3, 1) << endl;
    cout << s.kInversePairs(2, 2) << endl;
    cout << s.kInversePairs(3, 2) << endl;
    cout << s.kInversePairs(3, 3) << endl;
    cout << s.kInversePairs(1000, 1000) << endl;

    return 0;
}