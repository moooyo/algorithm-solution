#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define _DEBUG

int max(int a, int b)
{
    return a > b ? a : b;
}

class Solution
{
public:
    int getMoneyAmount(int n)
    {
        int dp[n + 1][n + 1];
        memset(dp, 9999999, sizeof(dp));
        for (int i = 1; i <= n; i++)
        {
            dp[i][i] = 0;
        }
        for (int r = 1; r < n; r++)
        {
            for (int i = 1; i < n && i + r <= n; i++)
            {

                for (int s = i; s < i + r; s++)
                {
                    int temp = s;
                    if (s == i)
                    {
                        temp = temp + dp[s + 1][i + r];
                    }
                    else if (s == i + r)
                    {
                        temp = temp + dp[i][s - 1];
                    }
                    else
                    {
                        temp = temp + max(dp[i][s - 1], dp[s + 1][i + r]);
                    }

                    if (temp < dp[i][i + r])
                    {
                        dp[i][i + r] = temp;
                    }
#ifdef DEBUG_
                    cout << "r: " << r << " i: " << i << " s: " << s << " dp[i][i+r]" << dp[i][i + r] << " temp: " << temp << endl;
#endif
                }
            }
        }
        return dp[1][n];
    }
};

// for test
int main()
{
    Solution s;
    cout << s.getMoneyAmount(10) << endl;

    return 0;
}